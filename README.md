[![Carthage compatible](https://img.shields.io/badge/Carthage-compatible-4BC51D.svg?style=flat)](https://github.com/Carthage/Carthage)

# Noteacons SDK

Welcome to Noteacons! Simple, effective and potent proximity campaigns. 

Check our [3 simple steps to launch guide](http://www.noteacons.com/support/) if you want to know more.

Check our [dashboad](http://panel.noteacons.com/) to create some nice campaigns.

Our full docs are [here](http://noteacons-docs.readthedocs.io).

## Get the Demo App

There's a demo app in this repository, but you can also check out or live demo: [Noteacons Beacon Simulator](https://itunes.apple.com/us/app/noteacons-beacon-simulator/id1136196655)

## Installation

The easiest way to integrate Noteacons in your project is using Carthage or CocoaPods:

###Carthage

```objc
github "Deveryware/noteacons-ios"
```

###CocoaPods

```objc
pod 'NoteaconsSDK'
```

###Download from dashboard

If you don't want to use Carthage or CocoaPods, you can download the SDK from the Dashboard and install following [this steps](http://noteacons-docs.readthedocs.io/en/latest/iOS/installation/).

## Integration

### Location Services

For iOS 8, enable the app to always use location services by adding NSLocationAlwaysUsageDescription key to your Info.plist file. This mode allows your app to be awaken when near beacons (via beacon region monitoring) and to receive detailled beacon data updates (via beacon ranging) for a few minutes while the app is in background. There is no restriction applying when the app in foreground. For example:

Key | Type | Value
--- | --- | ---
NSLocationAlwaysUsageDescription | String | This app will use your location information to identify ,nearby places and to notify you about available proximity experiences.


Make sure you provide a text that describes why and how you are going to use the user’s location. This text will be displayed to the user the first time you request the use of location services. Users are more likely to trust your app with location data if they understand why you need it.

If you aren't requesting the use of location services in your app, in your Application Delegate create a property:

```
@property (nonatomic, strong) CLLocationManager *locationManager;
```

Then, you can request authorization:

```
- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions {
    //...
    _locationManager = [[CLLocationManager alloc] init];
    [_locationManager requestAlwaysAuthorization];
    //...
}
```
[More info here.](https://developer.apple.com/library/ios/documentation/CoreLocation/Reference/CLLocationManager_Class/#//apple_ref/occ/instm/CLLocationManager/requestAlwaysAuthorization)

### Local Notifications

When a campaign must be launched and the application is in the background, we send a local notification. You must call this method during your launch cycle to request permission to alert the user:

```
- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions {
    //...
    if ([UIApplication instancesRespondToSelector:@selector(registerUserNotificationSettings:)]){

        UIUserNotificationType types = UIUserNotificationTypeBadge| UIUserNotificationTypeSound | UIUserNotificationTypeAlert;

        UIUserNotificationSettings *mySettings = [UIUserNotificationSettings settingsForTypes:types categories:nil];

        [[UIApplication sharedApplication] registerUserNotificationSettings:mySettings];
    }
    //...
}
```

## Usage

### Objective-c

* Import Noteacons SDK:

`@import NoteaconsSDK;`

* Start the SDK:

```
- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions {
    //...
    [[Noteacons manager] startSDKWithApiKey:@"API_KEY"
                                    apiSecret:@"API_SECRET"];
    //...
}
```

* Local Notifications:

```
- (void)application:(UIApplication *)application didReceiveLocalNotification:(UILocalNotification *)notification
{
    //...

    [[Noteacons manager] didReceiveLocalNotification:notification];

    //...
}
``` 

### Swift

* Adds Noteacons to your Bridging-Header:

```
#import <NoteaconsSDK/NoteaconsSDK.h>
```

* Start the SDK:

```
func application(application: UIApplication, didFinishLaunchingWithOptions launchOptions: [NSObject: AnyObject]?) -> Bool {
    //...
    
    let noteaconsSDK = Noteacons.manager() as Noteacons
    noteaconsSDK.startSDKWithApiKey("YOUR_API_KEY", apiSecret: "YOUR_API_SECRET")
    
    //...
}
```
* Local Notifications:

```
func application(application: UIApplication, didReceiveLocalNotification notification: UILocalNotification) {
    //...
    
    Noteacons.manager().didReceiveLocalNotification(notification)
    
    //...
}
```

## Customization

To learn more about Noteacons check the [customization docs](http://noteacons-docs.readthedocs.io/en/latest/iOS/customization/).
 





