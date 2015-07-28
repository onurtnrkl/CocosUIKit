//Created by Onur Tanrıkulu on 28/07/15.

#ifndef __UI_KIT_H__
#define __UI_KIT_H__

#include "cocos2d.h"
#include "SimpleAudioEngine.h"
#include "ui/CocosGUI.h"

using namespace cocos2d;
using namespace ui;

namespace UIKit
{
    enum XPosition{ Left, Center, Right };
    enum YPosition{ Bottom, Middle, Top };
    
    class UIButton
    {
    public:
        UIButton();
        void SetPosition(XPosition xPosition, YPosition yPosition);
    private:
        Size visibleSize;
        Vec2 origin;
    protected:
        ui::Button *button;
    };
    
    class CustomButton : public UIButton
    {
    public:
        void Create(const std::string &normalImage, const std::string &selectedImage, const cocos2d::ui::Button::ccWidgetTouchCallback &callback, cocos2d::Layer *layer);
    };
    
    class RateButton : public UIButton
    {
    public:
        RateButton();
        void Create(const std::string &normalImage, const std::string &selectedImage, cocos2d::Layer *layer);
    private:
        std::string rateUrl;
        void TouchEvent(Ref *sender);
    };
    
    class TwitterShareButton : public UIButton
    {
    public:
        TwitterShareButton();
        void Create(const std::string &normalImage, const std::string &selectedImage, cocos2d::Layer *layer);
    private:
        std::string twitterShareUrl;
        void TouchEvent(Ref *sender);
    };
    
    class FacebookShareButton : public UIButton
    {
    public:
        FacebookShareButton();
        void Create(const std::string &normalImage, const std::string &selectedImage, cocos2d::Layer *layer);
    private:
        std::string facebookShareUrl;
        void TouchEvent(Ref *sender);
    };
    
    class AudioToggleButton : public UIButton
    {
    public:
        void Create(const std::string &soundOnImage, const std::string &soundOffImage, cocos2d::Layer *layer);
    private:
        void TouchEvent(Ref *sender);
        float volume;
        std::string onImage;
        std::string offImage;
        std::string tempString;
    };
}

#endif // __UI_KIT_H__
