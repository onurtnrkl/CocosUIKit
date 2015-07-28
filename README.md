# Cocos-UIKit
Cocos UIKit is designed to help simplify the process of implementing ui tools.

Features
------------------------------------------
* Ready to use menu buttons.
* The Same UI Node Position is supporting all resolutions.
* Easy to use.

Ready Buttons
------------------------------------------
* Share via Twitter.
* Share via Facebook.
* Rate this App.
* Audio Toggle.
* Custom Button.(Button creation with custom Touch Event)

## Usage
Set Your App Settings from UIKitSettings.h
Use in your Scene.

## Example
```cpp
using UIKit;

CustomButton myButton1;

rateButton.Create("Normal.png", "Selected.png", this);
rateButton.SetPosition(Center, Middle);
```
