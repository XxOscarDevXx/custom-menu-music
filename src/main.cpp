#include <Geode/Geode.hpp>
#include <Geode/modify/MenuLayer.hpp>
#include <Geode/audio/CustomSongLayer.hpp>
#include <Geode/utils/file.hpp>
#include <Geode/ui/Notification.hpp>

using namespace geode::prelude;

class $modify(CustomMusicMenu, MenuLayer) {
    void onEnter() {
        MenuLayer::onEnter();

        auto path = Mod::get()->getSettingValue<std::string>("custom-music-path");

        if (!path.empty()) {
            if (!fileExists(path)) {
                Notification::create("Custom music file not found!", NotificationIcon::Error)->show();
                return;
            }

            CustomSongLayer::setCustomMenuSong(path);
            Notification::create("Custom menu music set!", NotificationIcon::Success)->show();
        } else {
            Notification::create("No custom music file selected.", NotificationIcon::Warning)->show();
        }
    }
};

