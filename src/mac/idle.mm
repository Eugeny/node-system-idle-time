#import <CoreFoundation/CoreFoundation.h>
#import <CoreGraphics/CoreGraphics.h>

/**
 Returns the number of seconds the machine has been idle or -1 if an error occurs.
 The code is compatible with Tiger/10.4 and later (but not iOS).
 */
int32_t SystemIdleTime(void) {
  return int32_t(CGEventSourceSecondsSinceLastEventType(
    kCGEventSourceStateCombinedSessionState,
    (CGEventType)(~(uint32_t)0)
  ));
}
