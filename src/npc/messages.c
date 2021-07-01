/*
** EPITECH PROJECT, 2021
** B-MUL-200-BDX-2-1-myrpg-solene.lefeu
** File description:
** messages
*/

#include "global.h"
#include <SFML/Graphics.h>

void show_message(sfRenderWindow *window, sfSprite *msg_box, sfText *text)
{
    sfRenderWindow_drawSprite(window, msg_box, NULL);
    sfRenderWindow_drawText(window, text, NULL);
}

void end_dialog(game_t *game)
{
    game->dialog->sprite = NULL;
    game->dialog->text = NULL;
    game->dialog->displayed = 0;
}

void click_message(__attribute__((unused))sfRenderWindow *window, sfEvent event,
game_t *game)
{
    sfMouseButtonEvent mouse_evt = event.mouseButton;
    sfFloatRect msg_bounds;
    dialog_t *dialog = game->dialog;
    int i = 0;

    if (dialog->sprite == NULL)
        return;
    msg_bounds = sfSprite_getGlobalBounds(dialog->sprite);
    msg_bounds = get_bounds_with_ratio(msg_bounds, game->res_ratio);
    if (mouse_evt.button != sfMouseLeft ||
        !sfFloatRect_contains(&msg_bounds, mouse_evt.x, mouse_evt.y))
        return;
    dialog->current++;
    for (node_t *node = dialog->messages; node != NULL; node = node->next) {
        if (dialog->current == i++) {
            sfText_setString(dialog->text, node->data);
            center_text_on_sprite(game->msg_box, dialog->text);
            return;
        }
    }
    end_dialog(game);
}