#include "Config.h"
#import "ModMenu.h"
#import "Hack.h"
#import "Hook.h"
#import "SliderHook.h"
#import "TextfieldHook.h"
#import <initializer_list>

UIAlertView *a;

uint64_t getRealOffset(uint64_t);

#define alert(x, y, z) a = [[UIAlertView alloc] initWithTitle:x message:y delegate:self cancelButtonTitle:z otherButtonTitles:nil]; \
[a show]; \

#define timer(sec) dispatch_after(dispatch_time(DISPATCH_TIME_NOW, sec * NSEC_PER_SEC), dispatch_get_main_queue(), ^ 

#define to_ns_str(cStr) [NSString stringWithCString:cStr encoding:NSUTF8StringEncoding]

#define PLIST_PATH @"/var/mobile/Library/Preferences/com.shmoo.menutest6.plist"

#define rgb(rgbValue) [UIColor \
 colorWithRed:((float)((rgbValue & 0xFF0000) >> 16))/255.0 \
 green:((float)((rgbValue & 0xFF00) >> 8))/255.0 \
 blue:((float)(rgbValue & 0xFF))/255.0 alpha:1.0]

inline bool GetPrefBool(NSString *key) {
                return [[[NSDictionary dictionaryWithContentsOfFile:PLIST_PATH] valueForKey:key] boolValue];
}

#define hide(type,name,value) __attribute__((visibility("hidden"))) type name = value;

OBJC_EXTERN CFStringRef MGCopyAnswer(CFStringRef key) WEAK_IMPORT_ATTRIBUTE;

#define NSFmt(x, ...) [NSString stringWithFormat:@x, __VA_ARGS__]

#define HOOK(offset, ptr, orig) MSHookFunction((void *)getRealOffset(offset), (void *)ptr, (void **)&orig)

/* private string CreateString(PTR value); (first one) */
monoString *(*String_CreateString)(void *_this, const char *str) = (monoString *(*)(void *, const char *))getRealOffset(0x1011ACD0C);

#define U3DStr(str) String_CreateString(NULL, str)

static NSString *const title = @"Static Tests";
static NSString *const credits = @"";
static NSString *const font = @"Copperplate-Bold";
static UIColor *const themeColor = rgb(arc4random_uniform(0xffffff));

UILabel *info;

void addHack(NSString *, NSString *, NSString *, std::initializer_list<uint64_t>, std::initializer_list<uint64_t>, std::initializer_list<uint64_t>);
void addHook(NSString *, NSString *, NSString *, uint64_t, void *, void *);
void addSliderHook(NSString *, NSString *, NSString *, float, float, uint64_t, void *, void *);
void addTextfieldHook(NSString *, NSString *, NSString *, uint64_t, void *, void *);

static ModMenu *menu;

bool buttonAdded;
int counter = 0;