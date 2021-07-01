/*
** EPITECH PROJECT, 2020
** my_owl
** File description:
** protos
*/

#ifndef PROTOS_H_
#define PROTOS_H_

#include "game.h"
#include "menu.h"
#include "text.h"
#include "transition.h"
#include "xml.h"
#include "ui.h"

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

#define BASE_HEIGHT 900
#define BASE_WIDTH 1600

#define MENU_BG_X 305
#define MENU_BG_Y 200
#define START_POS_X 350
#define START_POS_Y 265

#define	EXIT_FAIL 84

typedef int (*event)();
typedef void (*use_event)(game_t *, node_t *);

/*-----------------src/hero/hero_animation.c----------------*/
extern const sfVector2f scale;
extern const char *character_color_path[];
extern const anim_config_t hero_animations[];
named_animation_t *create_name_anim(const anim_config_t, int);
node_t *create_animation_list(const anim_config_t *, int);
animation_t *get_animation_w_name(node_t *, char *);
void animate_hero(game_t *);

/*-----------------src/hero/hero_spawn.c----------------*/
sfVector2f find_spawn(layer_t *);
sfVector2f get_player_spawn(game_t *);

/*-----------------src/hero/hero_movement.c----------------*/
void move_held_bomb(hero_t *);
void move_hero(game_t *);
void move_key_release(__attribute__((unused))sfRenderWindow *,
sfEvent, game_t *);
void move_key_press(__attribute__((unused))sfRenderWindow *, sfEvent, game_t *);
void move_lost_focus(__attribute__((unused))sfRenderWindow *,
__attribute__((unused))sfEvent, game_t *);

/*-----------------src/hero/hero_animate.c----------------*/
int animate_hurt(hero_t *);
int animate_attack(hero_t *);
void animate_run(hero_t *);
void animate_idle(hero_t *);
void show_damage(sfRenderWindow *, struct transiton_t *, game_t *);

/*-----------------src/hero/hero_utils.c----------------*/
sfVector2f get_hand_position(game_t *);
sfVector2f get_front_position(hero_t *, sfFloatRect);

/*-----------------src/hero/hero_struct.c----------------*/
void init_hero(hero_t *);
hero_t *create_hero(game_t *);

/*-----------------src/hero/hero_manager.c----------------*/
void handle_hero_damage(game_t *);
void animate_invicibility(game_t *);
void change_hero_direction(game_t *);
void ensure_hero_idle(hero_t *);
void handle_hero(sfRenderWindow *, game_t *, tile_t *);

/*-----------------src/hero/hero_bomb.c----------------*/
void handle_bomb_damage(game_t *);
void throw_bomb(hero_t *);
void draw_bomb(sfRenderWindow *, game_t *);
bomb_t *init_bomb(void);
bomb_t *create_bomb(hero_t *);

/*-----------------src/hero/hero_collision.c----------------*/
sfFloatRect get_feet_rect(game_t *);
int has_npc_collision(game_t *);
int next_tile_has_collision(game_t *);
int get_next_level(game_t *, int);
int get_current_level(game_t *);

/*-----------------src/hero/hero_attack.c----------------*/
void attack_key_press(__attribute__((unused))sfRenderWindow *,
sfEvent, game_t *);
void animate_sword(game_t *);
void animate_swipe(game_t *);
void stop_attack(game_t *);

/*-----------------src/xml_parser/properties.c----------------*/
property_t *get_next_property(char **line);
node_t *get_properties(char *);

/*-----------------src/xml_parser/data.c----------------*/
char *get_property(tag_t *, char *);
int get_property_int(tag_t *, char *, int);
tag_t *get_child(tag_t *, char *);

/*-----------------src/xml_parser/utils.c----------------*/
char *my_trim(char *);
void my_trimarr(char **arr);
char *get_tag_name(char *);
char *get_char_until(char *, char);
int is_tag_end(char *, char **lines, int);

/*-----------------src/xml_parser/inner.c----------------*/
int get_inner_end(char *, char **lines, int);
int get_inner_len(char **lines, int, int);
char *get_inner(char *, char **lines, int);

/*-----------------src/xml_parser/parse.c----------------*/
node_t *init_node(void);
int is_one_line(char *);
node_t *get_children(char *, char **lines, int);
tag_t *get_tag(char *, char **lines, int);
tag_t *parse_xml(char *);

/*-----------------src/map/map_collision.c----------------*/
tile_t *check_layers_at_position(layer_t *, sfFloatRect);
tile_t *get_tile_at_position(game_t *, sfFloatRect);

/*-----------------src/map/map_level.c----------------*/
int get_level(game_t *, sfFloatRect);

/*-----------------src/map/layer_property.c----------------*/
char *get_layer_property(layer_t *, char *);
property_t *create_property(char *, char *);
node_t *get_layer_properties(tag_t *);

/*-----------------src/map/map_list.c----------------*/
node_t *get_map_list(char *, game_t *);
map_t *get_map_from_id(game_t *, int);

/*-----------------src/map/map_change.c----------------*/
void move_map_sprites(map_t *, sfVector2f);
int get_next_map_index(game_t *);
void change_map(__attribute__((unused))sfRenderWindow *, game_t *);
sfVector2f get_map_change_offset(game_t *);
void animate_map_change(sfRenderWindow *, game_t *);

/*-----------------src/map/layer.c----------------*/
sfSprite *get_sprite_layer(int, map_t *, sfVector2f);
tile_t *get_tile_layer(int, map_t *, sfVector2f, layer_t *);
node_t *compute_sprite_layers(tag_t *, map_t *, layer_t *);
layer_t *generate_layer(tag_t *, map_t *);
node_t *generate_layers(tag_t *, map_t *);

/*-----------------src/map/map.c----------------*/
void set_mobs_position(map_t *);
void init_map(map_t *, tag_t *);
map_t *generate_map(char *, tag_t *, game_t *);

/*-----------------src/map/tileset.c----------------*/
tileset_property_t *get_tileset_property(tag_t *);
tileset_t *create_tileset(sfSprite *, int);
sfSprite *get_sprite_tile(int, tileset_property_t *);
node_t *compute_tileset(tag_t *, int *);
node_t *generate_tileset(tag_t *);

/*-----------------src/map/map_manager.c----------------*/
void show_layer(sfRenderWindow *, layer_t *, game_t *);
void show_map(sfRenderWindow *, game_t *, map_t *);
void reset_map(game_t *);
void handle_map_reset(game_t *);
void handle_map(sfRenderWindow *, game_t *);

/*-----------------src/handle_end/loose.c----------------*/
loose_t *init_loose(void);
void show_loose_menu(sfRenderWindow *, game_t *);
void reset_informations(game_t *);
void go_to_menu_no_save(__attribute__((unused))sfRenderWindow *, game_t *);
void handle_loose_click(sfRenderWindow *, sfEvent, game_t *);

/*-----------------src/quests/quest_manager.c----------------*/
void show_quest_panel(sfRenderWindow *, game_t *);
void check_quests(game_t *);
int quests_done(game_t *, int);
sfText *get_final_quest_text(char *);
void handle_quest(sfRenderWindow *, game_t *);

/*-----------------src/quests/quest_struct.c----------------*/
quests_t *init_quests(void);
quest_t *create_quest(int, char *);
void add_quest(game_t *, char *);

/*-----------------src/inventory/update_inventory.c----------------*/
void check_inventory(game_t *);
void update_box(object_t *, box_t *);
void store_in_inventory(object_t *, game_t *);

/*-----------------src/inventory/event_inventory.c----------------*/
void display_boxes(sfRenderWindow *, node_t *);
void handle_inventory(sfRenderWindow *, game_t *);
void display_inventory(__attribute__((unused))sfRenderWindow *,
sfEvent, game_t *);
void click_inventory(__attribute__((unused))sfRenderWindow *,
sfEvent, game_t *);
void handle_full_inventory(__attribute__((unused))sfRenderWindow *, game_t *);

/*-----------------src/inventory/event_objects.c----------------*/
void move_objects(node_t *, sfVector2f);
void handle_objects(sfRenderWindow *, node_t *, game_t *);
int check_collision_ground(sfSprite *, node_t *, game_t *, sfRenderWindow *);

/*-----------------src/inventory/use_items.c----------------*/
node_t *remove_from_inventory(game_t *, node_t *);
void display_dialog(game_t *, sfSprite *, sfText *, long);
void add_life(game_t *, node_t *);
void hold_bomb(game_t *, node_t *);
void raise_xp(game_t *, node_t *);

/*-----------------src/inventory/objects.c----------------*/
extern const char *item_list[];
extern const char *path_list[];
object_t *create_object(int, sfVector2f);
node_t *add_in_ground_list(int, sfVector2f, game_t *);
node_t *remove_of_ground_list(game_t *, node_t *);

/*-----------------src/inventory/init_inventory.c----------------*/
sfVector2f get_box_position(int, int);
box_t *create_box(int, int);
node_t *init_boxes(int, int);
inv_msg_t *init_inv_msg(void);
inventory_t *init_inventory(game_t *);

/*-----------------src/main.c----------------*/
void game_loop(sfRenderWindow *);
int check_env_display(char **env);
int gamestart(void);

/*-----------------src/options/fps.c----------------*/
void change_fps(sfRenderWindow *, char *, __attribute__((unused))game_t *);

/*-----------------src/options/character.c----------------*/
void change_character(__attribute__((unused))sfRenderWindow *,
char *, game_t *);

/*-----------------src/options/options_struct.c----------------*/
void init_options(options_t *, struct menu *, int);
void setup_options(options_t *, game_t *, int *);
options_t **create_options(struct menu *, game_t *);

/*-----------------src/options/audio.c----------------*/
sfSound *get_sound(char *);
void change_audio(__attribute__((unused))sfRenderWindow *, char *, game_t *);

/*-----------------src/options/resolution.c----------------*/
extern const float ratio[];
sfFloatRect get_bounds_with_ratio(sfFloatRect, float);
int get_res_width(char *);
int get_res_height(char *);
void change_resolution(sfRenderWindow *, char *, game_t *);

/*-----------------src/options/options_input.c----------------*/
void options_click_left(sfRenderWindow *, sfMouseButtonEvent, game_t *,
options_t *);
void options_click_right(sfRenderWindow *, sfMouseButtonEvent, game_t *,
options_t *);
void handle_options_click(sfRenderWindow *, sfEvent, game_t *);
int scale_on_hover(sfSprite *, sfVector2i, game_t *);
void handle_options_hover(__attribute__((unused))sfRenderWindow *, sfEvent,
game_t *);

/*-----------------src/mobs/wizz_stal.c----------------*/
animation_t *dup_animation(animation_t *);
stalactite_t *create_stalactite(mob_t *);
node_t *create_stalactite_list(mob_t *);
void draw_stal(sfRenderWindow *, stalactite_t *, game_t *);
void drop_stalactite(sfRenderWindow *, game_t *, mob_t *);

/*-----------------src/mobs/mob_animations.c----------------*/
named_animation_t *create_mob_anim(tag_t *);
node_t *create_mob_animation_list(tag_t *);
node_t *add_mob(node_t *, tag_t *, sfVector2f, game_t *);

/*-----------------src/mobs/mob_damage.c----------------*/
int is_hero_damaged(game_t *, mob_t *);
void check_hero_mob_collision(game_t *, mob_t *);
void check_hero_attack(game_t *, mob_t *);
void animate_mob_damage(__attribute__((unused))sfRenderWindow *, game_t *,
mob_t *);

/*-----------------src/mobs/godog.c----------------*/
void godog_attack(game_t *, mob_t *);
void start_spin_godog(game_t *, mob_t *);
void handle_godog_attack(game_t *, mob_t *);
void handle_godog(__attribute__((unused))sfRenderWindow *, game_t *, mob_t *);

/*-----------------src/mobs/beamos.c----------------*/
sfVector2f get_beam_position(mob_t *, int);
sfVector2f get_eye_position(mob_t *, int);
sfVector2f get_impact_position(mob_t *, int);
void animate_beam(sfRenderWindow *, game_t *, mob_t *, int);
void handle_beamos(sfRenderWindow *, game_t *, mob_t *);

/*-----------------src/mobs/ganon_jump.c----------------*/
int check_distance(sfVector2f, int);
void handle_jump_start_ganon(mob_t *);
void handle_jump_ganon(game_t *, mob_t *);
void handle_jump_down_ganon(mob_t *);
void handle_stomp_ganon(sfRenderWindow *, game_t *, mob_t *);

/*-----------------src/mobs/daira.c----------------*/
void handle_daira_animation(mob_t *, game_t *);
void handle_daira_idle(mob_t *, game_t *);
void handle_atk_daira(mob_t *, game_t *);
void handle_daira(__attribute__((unused))sfRenderWindow *, game_t *, mob_t *);

/*-----------------src/mobs/keese.c----------------*/
void handle_keese_animation(mob_t *, game_t *);
void handle_keese(__attribute__((unused))sfRenderWindow *, game_t *, mob_t *);

/*-----------------src/mobs/mob_jump.c----------------*/
sfVector2f calculate_velocity(sfVector2f, sfVector2f, int);
void handle_jump_up(game_t *, mob_t *);
void handle_jump_down(mob_t *);

/*-----------------src/mobs/mob_knockback.c----------------*/
int check_sprite_collision(game_t *, sfSprite *, sfVector2f);
void knockback_mob(game_t *, mob_t *);

/*-----------------src/mobs/lizalfos.c----------------*/
void handle_lizalfos_animation(mob_t *, game_t *);
void handle_lizalfos_idle(mob_t *);
void handle_lizalfos(__attribute__((unused))sfRenderWindow *, game_t *,
mob_t *);
void handle_enemy_type(sfRenderWindow *, game_t *, mob_t *);

/*-----------------src/mobs/tektite.c----------------*/
void check_attack_tektite(__attribute__((unused))sfRenderWindow *, game_t *,
mob_t *);
void move_tektite(mob_t *);
void handle_tektite(sfRenderWindow *, game_t *, mob_t *);

/*-----------------src/mobs/mobs_manager.c----------------*/
void handle_ganon(sfRenderWindow *, game_t *, mob_t *);
extern const enemy_handler_t enemy_handlers[];
float get_hero_distance(sfVector2f, sfVector2f);
sfVector2f get_movement(mob_t *, int);
void handle_mob(sfRenderWindow *, game_t *, mob_t *, tile_t *);
void handle_mobs(sfRenderWindow *, game_t *, tile_t *);
void move_maps_mobs(map_t *, sfVector2f);

/*-----------------src/mobs/mobs_layer.c----------------*/
char ***get_mob_ids(tag_t *, mob_layer_t *);
mob_layer_t *generate_mobs_layer(tag_t *, int);

/*-----------------src/mobs/godog_animation.c----------------*/
void handle_godog_animation(game_t *, mob_t *);
void handle_godog_start_animation(game_t *, mob_t *);
void handle_godog_end_animation(game_t *, mob_t *);

/*-----------------src/mobs/guitarman.c----------------*/
void handle_guitar_attack(game_t *, mob_t *);
void handle_guitar_projectile(sfRenderWindow *, game_t *, mob_t *);
void handle_guitar_boss(sfRenderWindow *, game_t *, mob_t *);

/*-----------------src/mobs/mobs_struct.c----------------*/
tag_t *get_mob_tag(int, tag_t *);
void init_mob(mob_t *);
void init_mob_property(mob_t *, tag_t *);
mob_t *get_mob_from_id(tag_t *, sfVector2f, game_t *);
node_t *generate_mobs(int, game_t *);

/*-----------------src/mobs/wizz.c----------------*/
void handle_wizz_damage(game_t *, stalactite_t *, mob_t *);
void handle_wizz_teleport(mob_t *);
void handle_wizz(sfRenderWindow *, game_t *, mob_t *);

/*-----------------src/mobs/octorok.c----------------*/
void is_facing_enemy(game_t *, mob_t *, int, int);
int is_sprite_ofs(sfSprite *);
sfVector2f get_octorok_direction(mob_t *);
void handle_octorok(sfRenderWindow *, game_t *, mob_t *);

/*-----------------src/mobs/ganon.c----------------*/
sfVector2f get_ganon_movement(mob_t *);
sfVector2f get_proj_movement(sfSprite *, hero_t *);
void handle_ganon_atk(mob_t *);
void handle_ganon_proj(sfRenderWindow *, game_t *, mob_t *);
void handle_ganon(sfRenderWindow *, game_t *, mob_t *);

/*-----------------src/mobs/mob_death.c----------------*/
void handle_ganon_death(__attribute__((unused))sfRenderWindow *, mob_t *,
game_t *);
void handle_mob_death(game_t *, mob_t *);

/*-----------------src/menu/menu_free.c----------------*/
void free_choices(struct menu *);
void free_menu(struct menu *);

/*-----------------src/menu/menu_utils.c----------------*/
void center_origin_sprite(sfSprite *);
void center_sprite(game_t *, sfSprite *, int);
void center_text(game_t *, sfText *, int, int);
int count_choices(const choice_t choices[]);

/*-----------------src/menu/menu_input.c----------------*/
extern const sfVector2f menu_bg_pos;
sfBool is_cursor_in_sprite(sfSprite *, sfVector2i, game_t *);
sfBool is_cursor_in_text(sfText *, sfVector2i, game_t *);
void handle_menu_click(sfRenderWindow *, sfEvent, game_t *);
void play_sound(int, sfSound *);
void handle_hover(sfRenderWindow *, game_t *, struct menu *);

/*-----------------src/menu/menu_event.c----------------*/
void exit_game(sfRenderWindow *, __attribute__((unused))game_t *);
void exit_save(sfRenderWindow *, game_t *);
void go_to_options(__attribute__((unused))sfRenderWindow *, game_t *);
void go_to_main_menu(__attribute__((unused))sfRenderWindow *, game_t *);
void go_to_how_to_play(__attribute__((unused))sfRenderWindow *, game_t *);

/*-----------------src/menu/pause_menu.c----------------*/
void handle_pause(__attribute__((unused))sfRenderWindow *, sfEvent, game_t *);
void show_pause_menu(sfRenderWindow *, game_t *);
void handle_pause_click(sfRenderWindow *, sfEvent, game_t *);

/*-----------------src/menu/menu_manager.c----------------*/
void resume_game(__attribute__((unused))sfRenderWindow *, game_t *);
void show_choices(sfRenderWindow *, struct menu *);
void show_menu(sfRenderWindow *, game_t *);
void show_options(sfRenderWindow *, game_t *);
void show_how_to_play(sfRenderWindow *, game_t *);

/*-----------------src/menu/save.c----------------*/
void write_line(int, int);
void write_in_file(game_t *);

/*-----------------src/menu/load_save.c----------------*/
void init_default_values(game_t *);
void load_save(__attribute__((unused))sfRenderWindow *, game_t *);
void init_from_file(game_t *, char **infos);
int get_from_file(game_t *);

/*-----------------src/menu/menu_struct.c----------------*/
extern const choice_t choices_main[];
extern const choice_t choices_pause[];
extern const choice_t choices_loose[];
menu_choice_t *create_menu_choice(char *, sfFont *,
void(*fptr)(sfRenderWindow *, game_t *));
void align_choices(menu_list_t *, struct menu *, game_t *,
const choice_t choices[]);
menu_list_t *create_menu_list(struct menu *, game_t *,
const choice_t choices[]);
void setup_menu(struct menu *, game_t *);
struct menu *load_menu(game_t *, const choice_t choices[]);

/*-----------------src/npc/npc_events.c----------------*/
void action_npc(game_t *, mob_t *);
void click_npc(__attribute__((unused))sfRenderWindow *, sfEvent, game_t *);

/*-----------------src/npc/messages.c----------------*/
void show_message(sfRenderWindow *, sfSprite *, sfText *);
void end_dialog(game_t *);
void click_message(__attribute__((unused))sfRenderWindow *, sfEvent, game_t *);

/*-----------------src/npc/npc_struct.c----------------*/
extern const anim_config_t npc_animations[];
sfSprite *create_message_box(void);
npc_t *generate_npc(void);

/*-----------------src/npc/npc_manager.c----------------*/
sfBool sprite_in_reach(sfSprite *, sfSprite *, int);

/*-----------------src/npc/message_struct.c----------------*/
node_t *get_msg_list(tag_t *);
void center_text_on_sprite(sfSprite *, sfText *);
sfText *create_msg(sfSprite *, char *);

/*-----------------src/effect/struct.c----------------*/
effect_t *create_effect(const char *, int);

/*-----------------src/design/sprites.c----------------*/
void check_file_path(const char *);
sfSprite *load_sprite(const char *);

/*-----------------src/design/transitions.c----------------*/
void draw_bands(sfRenderWindow *);
void draw_win_msg(sfRenderWindow *);
struct transiton_t *create_transition(void);
void fade(sfRenderWindow *, struct transiton_t *, int *);

/*-----------------src/design/background.c----------------*/
sfTexture *load_background(char *);
sfSprite *create_background(char *);
void show_background(sfRenderWindow *, sfSprite *);

/*-----------------src/design/particule_engine.c----------------*/
extern const particle_settings_t settings_list[];
node_t *delete_particle(particle_engine_t *, particle_t *);
particle_t *create_particle(particle_settings_t);
node_t *create_particle_list(particle_settings_t, int);
void fuel_engine(particle_engine_t *, int);
particle_engine_t *create_engine(particle_settings_t, int);

/*-----------------src/design/font.c----------------*/
void print_text(sfRenderWindow *, struct text_sprite, sfFont *, sfText *);
sfText *create_text(sfFont *, int);

/*-----------------src/design/animation.c----------------*/
void handle_animation(sfRenderWindow *, animation_t *);
void draw_animation(sfRenderWindow *, animation_t *, game_t *);
void init_animation(animation_t *);
animation_t *create_animation(const char *, int, int, sfVector2f);
int is_animation_ended(animation_t *);

/*-----------------src/design/particule_update.c----------------*/
void update_particule(particle_settings_t, particle_t *);
void update_particule_engine(particle_engine_t *, particle_settings_t);

/*-----------------src/design/cinematic.c----------------*/
cinematic_t *init_cinematic(void);
void load_cinematic(__attribute__((unused))sfRenderWindow *, cinematic_t *,
game_t *);
void draw_cinematic_background(sfRenderWindow *);
void reset_cinematic(cinematic_t *);
void handle_cinematic(sfRenderWindow *, cinematic_t *, game_t *);

/*-----------------src/design/particle_display.c----------------*/
void draw_line_between_position(sfRenderWindow *, sfVector2f, sfVector2f,
particle_t *);
void handle_trace(__attribute__((unused))particle_engine_t *, particle_t *,
sfRenderWindow *);
void add_gravity(particle_engine_t *, particle_t *);
void handle_dissolve(particle_engine_t *, particle_t *);
void draw_particles(sfRenderWindow *, particle_engine_t *);

/*-----------------src/utils/mem_alloc_2d_array.c----------------*/
int random_val(void);
sfText *init_inv_text(char const *);
char **mem_alloc_2d_array(int, int);

/*-----------------src/utils/free.c----------------*/
void free_sound(sfSound *);
void free_sprite(sfSprite *);
void free_2d_array(char **array);

/*-----------------src/utils/load_2d_arr_from_file.c----------------*/
int nb_size(int);
char **load_2d_arr_from_file(char const *, int, int);

/*-----------------src/utils/load_file_in_mem.c----------------*/
int is_file_existing(const char *);
int get_file_size(char const *);
char *load_file_in_mem(char const *);
int count_rows(char *);
int *convert_buffer(char *);

/*-----------------src/utils/text.c----------------*/
sfText *create_texts(const char *, sfVector2f, sfColor);
char *create_str(char *, char *);

/*-----------------src/hud/dialog.c----------------*/
void show_dialog(sfRenderWindow *, game_t *);
dialog_t *create_dialog(void);

/*-----------------src/hud/life.c----------------*/
life_t init_lives(void);
void draw_heart(sfSprite *, sfVector2f, sfRenderWindow *);
void display_lives(sfRenderWindow *, game_t *);

/*-----------------src/hud/hud_utils.c----------------*/
char *get_text(const char *, long);
char *get_score(long);

/*-----------------src/stats_menu/update_level.c----------------*/
void check_res_increase(game_t *);
void check_level(game_t *);

/*-----------------src/stats_menu/init_stats.c----------------*/
void set_stats_infos(stats_t *, game_t *);
void set_size_texts(stats_t *);
void set_sprite_infos(game_t *, stats_t *);
stats_t *init_stat_struct(game_t *);

/*-----------------src/stats_menu/display_stats.c----------------*/
void check_stats(game_t *);
void print_stats(sfRenderWindow *, game_t *);
void handle_stats(sfRenderWindow *, game_t *);
void display_stats(__attribute__((unused))sfRenderWindow *, sfEvent, game_t *);

/*-----------------src/game/game_start.c----------------*/
void show_loading_screen(sfRenderWindow *);
void show_help_message(void);

/*-----------------src/game/game_manager.c----------------*/
void set_text_property(sfText *, sfVector2f, int, sfColor);
void set_center_position(sfText *, int, game_t *);
void start_game(__attribute__((unused))sfRenderWindow *, game_t *);
void check_special_display(sfRenderWindow *, game_t *);
void show_game(sfRenderWindow *, game_t *);

/*-----------------src/game/event_manager.c----------------*/
extern event_t EVENT_LIST[];
void check_events(sfRenderWindow *, sfEvent, game_t *);
void handle_event(sfRenderWindow *, sfEvent, game_t *);
void handle_htp_hover(__attribute__((unused))sfRenderWindow *, sfEvent,
game_t *);
void handle_htp_click(sfRenderWindow *, sfEvent, game_t *);

/*-----------------src/game/game_display.c----------------*/
void display_game(sfRenderWindow *, game_t *);

/*-----------------src/game/game.c----------------*/
void setup_game_var(game_t *);
game_t *load_game(int, int, sfRenderWindow *);
void play_music(game_t *);
void change_state(sfRenderWindow *, game_t *);
void check_victory(sfRenderWindow *, game_t *);

#endif /* !PROTOS_H_ */