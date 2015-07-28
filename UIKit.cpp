//Created by Onur Tanrıkulu on 28/07/15.

#include "UIKit.h"
#include "UIKitSettings.h"

#define APPSTORE_URL "https%3A%2F%2Fitunes.apple.com%2Fapp%2Fid"
#define GOOGLEPLAY_URL "https%3A%2F%2Fplay.google.com%2Fstore%2Fapps%2Fdetails%3Fid%3D"

USING_NS_CC;
using namespace UIKit;

UIButton::UIButton()
{
    visibleSize = Director::getInstance()->getVisibleSize();
    origin = Director::getInstance()->getVisibleOrigin();
}

void UIButton::SetPosition(XPosition xPosition, YPosition yPosition)
{
    switch (xPosition)
    {
        case Left:
            button->cocos2d::Node::setPositionX(button->getContentSize().width/2 + origin.x);
            break;
        case Center:
            button->cocos2d::Node::setPositionX(visibleSize.width/2 + origin.x);
            break;
        case Right:
            button->cocos2d::Node::setPositionX(visibleSize.width - button->getContentSize().width/2 + origin.x);
            break;
    }
    
    switch (yPosition)
    {
        case Bottom:
            button->cocos2d::Node::setPositionY(button->getContentSize().height/2 + origin.y);
            break;
        case Middle:
            button->cocos2d::Node::setPositionY(visibleSize.height/2 + origin.y);
            break;
        case Top:
            button->cocos2d::Node::setPositionY(visibleSize.height - button->getContentSize().height/2 + origin.y);
            break;
    }
}

#if RATE_BUTTON_ENABLED == true
RateButton::RateButton()
{
    if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
        rateUrl = "itms-apps://itunes.apple.com/app/id" APPSTORE_APP_ID;
    else if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
        rateUrl = "market://details?id=" GOOGLEPLAY_PACKAGE_NAME;
    else CCLOG("Rate Button is only working on iOS and Android");
}

void RateButton::TouchEvent(cocos2d::Ref *sender)
{
    Application::getInstance()->openURL(rateUrl);
}

void RateButton::Create(const std::string &normalImage, const std::string &selectedImage, cocos2d::Layer *layer)
{
    button = ui::Button::create(normalImage, selectedImage);
    button->addTouchEventListener(CC_CALLBACK_1(RateButton::TouchEvent, this) );
    layer->addChild(button, 100);
}
#endif

#if TWITTER_SHARE_BUTTON_ENABLED == true
TwitterShareButton::TwitterShareButton()
{
    if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
        twitterShareUrl = "http://twitter.com/intent/tweet?text=" APPSTORE_URL APPSTORE_APP_ID;
    else if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
        twitterShareUrl = "http://twitter.com/intent/tweet?text=" GOOGLEPLAY_URL GOOGLEPLAY_PACKAGE_NAME;
    else CCLOG("Twitter Share Button is only working on iOS and Android");
}

void TwitterShareButton::TouchEvent(cocos2d::Ref *sender)
{
    Application::getInstance()->openURL(twitterShareUrl);
}

void TwitterShareButton::Create(const std::string &normalImage, const std::string &selectedImage, cocos2d::Layer *layer)
{
    button = ui::Button::create(normalImage, selectedImage);
    button->addTouchEventListener(CC_CALLBACK_1(TwitterShareButton::TouchEvent, this) );
    layer->addChild(button, 100);
}
#endif

#if FACEBOOK_SHARE_BUTTON_ENABLED == true
FacebookShareButton::FacebookShareButton()
{
    if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
        facebookShareUrl = "http://www.facebook.com/sharer/sharer.php?u=" APPSTORE_URL APPSTORE_APP_ID;
    else if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
        facebookShareUrl = "http://www.facebook.com/sharer/sharer.php?u=" GOOGLEPLAY_URL GOOGLEPLAY_PACKAGE_NAME;
    else CCLOG("Facebook Share Button is only working on iOS and Android");
}

void FacebookShareButton::TouchEvent(cocos2d::Ref *sender)
{
    Application::getInstance()->openURL(facebookShareUrl);
}

void FacebookShareButton::Create(const std::string &normalImage, const std::string &selectedImage, cocos2d::Layer *layer)
{
    button = ui::Button::create(normalImage, selectedImage);
    button->addTouchEventListener(CC_CALLBACK_1(FacebookShareButton::TouchEvent, this) );
    layer->addChild(button, 100);
}
#endif

#if AUDIO_TOGGLE_BUTTON_ENABLED == true
void AudioToggleButton::TouchEvent(cocos2d::Ref *sender)
{
    if (CocosDenshion::SimpleAudioEngine::getInstance()->getEffectsVolume( ) > 0.0f ||
        CocosDenshion::SimpleAudioEngine::getInstance()->getBackgroundMusicVolume() > 0.0f)
    {
        volume = 1.0f;
        tempString = onImage;
    }
    else
    {
        volume = 0.0f;
        tempString = offImage;
    }
    
    button->loadTextureNormal(tempString);
    CocosDenshion::SimpleAudioEngine::getInstance()->setEffectsVolume(volume);
    CocosDenshion::SimpleAudioEngine::getInstance()->setBackgroundMusicVolume(volume);
}

void AudioToggleButton::Create(const std::string &soundOnImage, const std::string &soundOffImage, cocos2d::Layer *layer)
{
    onImage = soundOnImage;
    offImage = soundOffImage;
    
    button = ui::Button::create(soundOnImage);
    button->addTouchEventListener(CC_CALLBACK_1(AudioToggleButton::TouchEvent, this));
    layer->addChild(button, 100);
}
#endif
