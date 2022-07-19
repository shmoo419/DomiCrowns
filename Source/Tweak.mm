#import "Macros.h"
#import "GlobalVars.h"
#import <substrate.h>
#import <vector>
#import <mach-o/dyld.h>
#import <pthread/pthread.h>

uint64_t getASLRSlide(){
	return _dyld_get_image_vmaddr_slide(0);
}

void *modifyGlobalVars(void *arg){
	while(true){
		void *baseAddress = *(void **)(getASLRSlide() + 0x102cbb870);
		
		if(baseAddress){
			GlobalVars *Vars = *(GlobalVars **)((uint64_t)baseAddress + 0xa0);
			
			if(Vars){
				Vars->STARTING_GEMS = 500000;
				
				// we don't need this thread anymore, why keep setting our starting crowns to 500000?
				pthread_exit(NULL);
			}
		}
		
		// sleep for a millisecond
		usleep(1 * 1000);
	}
	
	return NULL;
}

%hook UnityAppController

- (void)applicationDidBecomeActive:(id)arg0 {
	// create and spawn our thread
	pthread_t modifyGlobalVarsThread;
	pthread_create(&modifyGlobalVarsThread, NULL, modifyGlobalVars, NULL);
	
	%orig;
}

// not needed, I always have this here though
uint64_t getRealOffset(uint64_t offset){
    return _dyld_get_image_vmaddr_slide(0) + offset;
}
