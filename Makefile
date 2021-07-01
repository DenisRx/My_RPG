##
## EPITECH PROJECT, 2020
## makefile
## File description:
## make
##

SRC		=	src/main.c 						\
			src/design/background.c 		\
			src/design/font.c 				\
			src/design/sprites.c 			\
			src/design/transitions.c 		\
			src/design/cinematic.c 			\
			src/design/particule_engine.c 	\
			src/design/particle_display.c 	\
			src/design/particule_update.c 	\
			src/effect/struct.c 			\
			src/game/game_start.c	 		\
			src/game/game_display.c	 		\
			src/game/event_manager.c 		\
			src/game/game_manager.c 		\
			src/game/game.c 				\
			src/hud/hud_utils.c 			\
			src/hud/life.c					\
			src/hud/dialog.c				\
			src/menu/menu_event.c 			\
			src/menu/menu_input.c 			\
			src/menu/menu_manager.c 		\
			src/menu/menu_struct.c 			\
			src/menu/menu_utils.c 			\
			src/menu/menu_free.c 			\
			src/menu/pause_menu.c			\
			src/menu/load_save.c 			\
			src/utils/load_file_in_mem.c	\
			src/utils/text.c				\
			src/utils/free.c				\
			src/utils/mem_alloc_2d_array.c	\
			src/design/animation.c			\
			src/options/options_struct.c	\
			src/options/options_input.c		\
			src/options/resolution.c		\
			src/options/character.c			\
			src/options/fps.c				\
			src/options/audio.c				\
			src/hero/hero_manager.c 		\
			src/hero/hero_struct.c 			\
			src/hero/hero_movement.c		\
			src/hero/hero_attack.c			\
			src/hero/hero_utils.c			\
			src/hero/hero_animate.c			\
			src/hero/hero_animation.c		\
			src/hero/hero_collision.c		\
			src/hero/hero_spawn.c			\
			src/hero/hero_bomb.c			\
			src/map/map.c 					\
			src/map/layer.c 				\
			src/map/layer_property.c 		\
			src/map/map_change.c	 		\
			src/map/tileset.c 				\
			src/map/map_manager.c			\
			src/map/map_collision.c			\
			src/map/map_list.c				\
			src/map/map_level.c				\
			src/xml_parser/parse.c			\
			src/xml_parser/utils.c			\
			src/xml_parser/properties.c		\
			src/xml_parser/inner.c			\
			src/xml_parser/data.c			\
			src/stats_menu/init_stats.c		\
			src/stats_menu/display_stats.c	\
			src/stats_menu/update_level.c	\
			src/npc/npc_struct.c			\
			src/npc/npc_manager.c			\
			src/npc/message_struct.c		\
			src/npc/messages.c				\
			src/npc/npc_events.c			\
			src/menu/save.c					\
			src/mobs/tektite.c				\
			src/mobs/keese.c				\
			src/mobs/beamos.c				\
			src/mobs/daira.c				\
			src/mobs/guitarman.c			\
			src/mobs/lizalfos.c				\
			src/mobs/octorok.c				\
			src/mobs/godog.c				\
			src/mobs/godog_animation.c		\
			src/mobs/ganon.c				\
			src/mobs/ganon_jump.c			\
			src/mobs/wizz.c					\
			src/mobs/wizz_stal.c			\
			src/mobs/mob_jump.c				\
			src/mobs/mob_death.c			\
			src/mobs/mob_knockback.c		\
			src/mobs/mob_damage.c			\
			src/mobs/mob_animations.c		\
			src/mobs/mobs_struct.c			\
			src/mobs/mobs_manager.c			\
			src/mobs/mobs_layer.c			\
			src/quests/quest_struct.c		\
			src/quests/quest_manager.c		\
			src/handle_end/loose.c			\
			src/inventory/event_inventory.c	\
			src/inventory/event_objects.c	\
			src/inventory/init_inventory.c	\
			src/inventory/objects.c			\
			src/inventory/update_inventory.c\
			src/inventory/use_items.c

OBJ				=		$(SRC:.c=.o)

NAME            =       my_rpg

CFLAGS          =       -Wall -Wextra

CPPFLAGS        =       -I ./include/ -g

LDFLAGS 		=		-L./lib

LDLIBS          =       -lmy -lcsfml-graphics -lcsfml-window -lcsfml-system -lcsfml-audio -lm

LIB				=		lib/libmy.a

RM              =       rm -f

$(NAME):	$(LIB) $(OBJ)
		gcc -o $(NAME) $(OBJ) $(CPPFLAGS) $(LDFLAGS) $(LDLIBS) $(CFLAGS)

all:	$(NAME)

$(LIB):
		make -C lib/my
		make -C lib/my fclean

clean:
		$(RM) -r $(OBJ)
		$(RM) vgcore.* *~ src/*~ include/*~
		make -C lib/my $@

fclean:	clean
	$(RM) $(NAME)
	make -C lib/my $@

re:	fclean all

.PHONY: all tests_run clean fclean re
