/*
** EPITECH PROJECT, 2020
** my_ls
** File description:
** game
*/

#ifndef GAME_H_
#define GAME_H_

#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include "transition.h"
#include "menu.h"
#include "ui.h"
#include "state.h"

typedef struct effect {
    sfSprite *sprite;
    sfTexture *texture;
    sfVector2f scaling;
    sfVector2u texture_size;
    sfIntRect rectangle;
    int sprite_nb;
} effect_t;

typedef struct cinematic
{
    sfSprite *sprite;
    sfVector2f movement;
    sfVector2f pos;
    sfClock *movement_clock;
    sfClock *pause_clock;
    sfText *text;
    int delay;
    int played;
    int loaded;
}cinematic_t;

typedef struct animation {
    sfSprite *sprite;
    sfTexture *texture;
    sfVector2f position;
    sfVector2f scaling;
    sfVector2u texture_size;
    sfColor color;
    sfClock *movement_clock;
    sfClock *animation_clock;
    sfIntRect rectangle;
    int current_frame;
    int sprite_nb;
    int lines_nb;
    int delay;
    int pause;
    int play_count;
    sfVector2f velocity;
} animation_t;

typedef enum direction {
    RIGHT,
    BOT,
    LEFT,
    TOP
} direction_t;

enum CHARACTER_COLOR {
    GREEN,
    BLUE,
    PURPLE,
    RED
};

typedef struct node {
    void *data;
    struct node *next;
} node_t;

#include "xml.h"

typedef struct named_animation {
    char *name;
    animation_t *animation;
} named_animation_t;

typedef struct bomb {
    sfSprite *sprite;
    animation_t *animation;
    int is_held;
    int reach;
    int damage;
    float velocity;
    sfVector2f movement;
    sfClock *throw_clock;
} bomb_t;

typedef struct hero {
    animation_t *sword_animation;
    animation_t *swipe_animation;
    animation_t *animation;
    node_t *animation_list;
    sfVector2f knockback;
    float velocity;
    int is_getting_damage;
    int is_moving;
    int lives;
    int is_attacking;
    int damage;
    int speed;
    int level;
    int xp;
    int critical_chance;
    int resistance;
    sfClock *invicibilty;
    sfClock *invic_anim;
    sfClock *movement_clock;
    sfClock *jump_clock;
    sfClock *knockback_clock;
    sfVector2f movement;
    sfVector2f position;
    direction_t direction;
    bomb_t *bomb;
    enum CHARACTER_COLOR color;
} hero_t;

typedef struct mob {
    animation_t *animation;
    animation_t *projectile;
    animation_t *dying_animation;
    sfVector2f current_jump;
    sfVector2f velocity;
    node_t *animation_list;
    int type;
    float life;
    float damage;
    float reach;
    int xp;
    int is_getting_damage;
    int is_moving;
    int is_attacking;
    int displayed;
    int is_npc;
    int quest_id;
    int knockback;
    int jump_down;
    int state;
    float gravity;
    sfClock *idle_clock;
    sfClock *dmg_clock;
    sfClock *invicibilty;
    sfClock *movement_clock;
    sfClock *knockback_clock;
    sfClock *jump_clock;
    sfVector2f position;
    sfVector2f movement;
    sfVector2f next_position;
    sfVector2f start_indexes;
    direction_t direction;
    node_t *msg_list;
    sfText *current_msg;
    node_t *misc;
} mob_t;

typedef struct cell {
    char type;
    sfSprite *sprite;
} cell_t;

typedef struct npc {
    int id;
    int quest_id;
} npc_t;

typedef struct map {
    int id;
    node_t *tileset;
    node_t *layers;
    node_t *objects;
    int tilewidth;
    int tileheight;
    int height;
    int width;
    int top;
    int left;
    int right;
    int bot;
    int music_id;
    char *music_path;
    node_t *mobs;
    tag_t *tag;
} map_t;

typedef struct {
    sfSprite *msg_bg;
    sfText *full_inv_err;
    sfText *full_life_err;
    sfText *hold_err;
    sfText *level_up;
    sfText *gain_xp;
    sfClock *clock;
} inv_msg_t;

typedef struct inventory {
    int total_elem;
    int remaining;
    int offset;
    int displayed;
    sfSprite *sprite;
    node_t *boxes;
    sfText *title;
    inv_msg_t *inv_msg;
} inventory_t;

typedef struct {
    int max_lives;
    int remaining_lives;
    int semi;
    sfSprite *sprite_half;
    sfSprite *sprite_full;
    sfSprite *sprite_empty;
} life_t;

typedef struct dialog {
    sfSprite *sprite;
    sfText *text;
    sfClock *clock;
    node_t *messages;
    int current;
    long delay;
    int displayed;
} dialog_t;

typedef struct quest {
    int id;
    sfText *title;
    int status;
    sfSprite *in_progress;
    sfSprite *done;
} quest_t;

typedef struct quests {
    sfSprite *box_bg;
    sfText *box_title;
    int quest_nb;
    node_t *quest_list;
} quests_t;

typedef struct {
    sfText *title;
    sfSprite *background;
    int lost;
} loose_t;

typedef struct particle_settings {
    float angle;
    sfColor color;
    int speed;
    int dissolve;
    int dissolve_rate;
    int gravity;
    int bouncing;
    int size;
    sfFloatRect origin_rect;
    sfVector2f velocity;
    int trace;
} particle_settings_t;

typedef struct particle {
    float angle;
    sfColor color;
    int speed;
    int dissolve;
    int dissolve_rate;
    int gravity;
    int bouncing;
    int size;
    int trace;
    long delay;
    sfClock *delay_clock;
    sfVector2f velocity;
    sfClock *dissolve_clock;
    sfFloatRect origin_rect;
    sfCircleShape *shape;
    sfVector2f prev_pos;
} particle_t;

typedef struct particle_engine {
    particle_settings_t settings;
    node_t *particles;
    int nb_particles;
} particle_engine_t;

typedef struct game {
    sfRenderWindow *window;
    sfSprite *msg_box;
    sfSprite *background;
    node_t *maps;
    map_t *map;
    map_t *next_map;
    int current_map;
    direction_t map_direction;
    sfVector2f map_reset_offset;
    sfVector2f map_offset;
    sfClock *map_clock;
    struct menu *menu;
    struct menu *pause;
    struct menu *loose;
    int paused;
    hero_t *hero;
    life_t life_infos;
    struct transiton_t *damage_anim;
    struct transiton_t *transition;
    sfVector2u resolution;
    dialog_t *dialog;
    float res_ratio;
    STATE state;
    int next_state;
    int save;
    inventory_t *inventory;
    stats_t *stats;
    npc_t *npc;
    sfMusic *music_game;
    quests_t *quests;
    loose_t *loose_elems;
    cinematic_t *cinematic;
    int win;
    sfClock *win_clock;
    particle_engine_t *engine;
} game_t;

typedef struct event {
    STATE state;
    void (*event)(sfRenderWindow* window, sfEvent event, game_t *game);
    sfEventType type;
} event_t;

typedef struct tileset {
    int index;
    sfSprite *sprite;
} tileset_t;

typedef struct tileset_property {
    int width;
    int height;
    int tilewidth;
    int tileheight;
    int tile_count;
    int columns;
    char *path;
} tileset_property_t;

typedef struct tile {
    int level;
    int has_collision;
    sfVector2f indexes;
    sfSprite *sprite;
} tile_t;

typedef struct layer {
    char *name;
    int width;
    int height;
    node_t *sprites;
    node_t *properties;
    int visible;
} layer_t;

typedef struct mob_layer {
    int map_id;
    int width;
    int height;
    char ***ids;
} mob_layer_t;

typedef struct anim_config {
    char *name;
    char *path;
    int sprite_nb;
    int line;
    sfVector2f scale;
    int delay;
} anim_config_t;

typedef struct enemy_handler {
    int mob_type;
    void (*fn)(sfRenderWindow *, game_t *, mob_t *);
} enemy_handler_t;

typedef struct stalactite {
    sfSprite *stalactite;
    sfSprite *shadow;
    animation_t *impact;
    animation_t *drop;
    sfVector2f target;
    sfVector2f position;
    sfClock *clock;
    int current;
} stalactite_t;

enum particle_type { SNOW, RAIN, WIND };

#endif /* !GAME_H_ */
