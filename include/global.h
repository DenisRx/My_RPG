/*
** EPITECH PROJECT, 2021
** Epitech (Workspace)
** File description:
** global
*/

#ifndef GLOBAL_H_
#define GLOBAL_H_

#include "my.h"
#include "menu.h"
#include "game.h"
#include "protos.h"
#include "text.h"
#include "state.h"
#include "xml.h"
#include "ui.h"

/*                      MENU                     */
#define LOGO "assets/backgrounds/logo.png"
#define START_MENU_BG "assets/backgrounds/back.png"
#define BLACK_BG "assets/backgrounds/black_bg.jpg"

/*                      HUD                     */
#define HALF_HEART "assets/hud/half_heart.png"
#define EMPTY_HEART "assets/hud/empty_heart.png"
#define FULL_HEART "assets/hud/full_heart.png"
#define MENU_BG "assets/backgrounds/menu_bg.png"
#define STATS_BG "assets/hud/status.png"
#define HTP_HUD "assets/hud/how_to_play.png"
#define QUEST_BOX "assets/backgrounds/black.png"
#define MSG_BOX "assets/backgrounds/black2.png"
#define TICK "assets/hud/tick.png"
#define EMPTY_CIRCLE "assets/hud/circle.png"

/*                      INVENTORY               */
#define INVENTORY "assets/hud/inventory.png"
#define MSG_INV "assets/backgrounds/black.png"
#define FULL_INV_ERR "You can't pick that up,\nyour inventory is full!"
#define FULL_LIFE_ERR "You can't use that potion,\nyour life is already full!"
#define HOLD_ERR "You can't use this item,\nyou're already holding one!"
#define GAIN_XP "+20 XP"
#define GAIN_LVL "Level up!"
#define NB_TYPES 3

/*                      OBJECTS                 */
#define BOMB_SPRITE "assets/hud/bomb.png"
#define BOMB_ANIM "assets/bomb_explosion.png"

/*                      NPC                     */
#define START_MENU_BG_ARROW "assets/hud/arrowL_10x16.png"
#define NEXT_ARROW "assets/hud/arrowR_10x16.png"
#define NPC_REACH 300
#define MSG_SIZE 25

/*                      FONTS                   */
#define TITLE_FONT "assets/font/titles.otf"
#define MSG_FONT "assets/font/in_game.ttf"
#define MENU_FONT "assets/font/pixelart.ttf"

/*                      MUSICS                  */
#define MENU_MUSIC "assets/sounds/menu.ogg"
#define SOUND_HOVER "assets/sounds/menu_hover.ogg"
#define SOUND_SELECT "assets/sounds/menu_select.ogg"
#define MAIN_MUSIC "assets/sounds/main.ogg"

/*                  MISCELLANEOUS               */
#define FILE_PATH "save.txt"

#define GANON_AVAILABLE "You have defeated all region monsters\n" \
    "Your final quest is to kill Ganon!"
#define GANON_NOT_AVAILABLE "You can't enter Hyrule's castle\n" \
    "before you defeat all region monsters!"
#define VICTORY "You won!"

#endif /* !GLOBAL_H_ */