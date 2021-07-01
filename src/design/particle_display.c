/*
** EPITECH PROJECT, 2021
** B-MUL-200-BDX-2-1-myrpg-solene.lefeu
** File description:
** particle_display
*/

#include "global.h"
#include <math.h>

void draw_line_between_position(sfRenderWindow* window, sfVector2f origin_pos,
sfVector2f dest_pos, particle_t *info)
{
    sfRectangleShape *line = sfRectangleShape_create();
    double distance;
    float angle;

    distance = sqrt(pow(dest_pos.y - origin_pos.y, 2) +
    pow(dest_pos.x - origin_pos.x, 2));
    angle = atan2f(dest_pos.y - origin_pos.y, dest_pos.x - origin_pos.x) *
    180 / M_PI;
    sfRectangleShape_setSize(line, (sfVector2f){distance * 3, info->size});
    sfRectangleShape_setPosition(line, origin_pos);
    sfRectangleShape_setFillColor(line, info->color);
    sfRectangleShape_setRotation(line, angle);
    sfRenderWindow_drawRectangleShape(window, line, NULL);
    sfRectangleShape_destroy(line);
}

void handle_trace(__attribute__((unused))particle_engine_t *engine,
particle_t *info, sfRenderWindow* window)
{
    sfVector2f current_pos = sfCircleShape_getPosition(info->shape);
    if (info->trace == 0)
        return;
    draw_line_between_position(window, current_pos, info->prev_pos, info);
}

void add_gravity(particle_engine_t *engine, particle_t *info)
{
    sfFloatRect rect = sfCircleShape_getGlobalBounds(info->shape);
    sfVector2f weight = {0, info->gravity + 1};

    sfCircleShape_move(info->shape, weight);
    if (rect.top >= BASE_HEIGHT) {
        engine->particles = delete_particle(engine, info);
        fuel_engine(engine, 1);
    }
}

void handle_dissolve(particle_engine_t *engine, particle_t *particle)
{
    if (sfClock_getElapsedTime(particle->dissolve_clock).microseconds > 50000) {
        sfClock_restart(particle->dissolve_clock);
        particle->color.a -= rand() % particle->dissolve_rate;
        sfCircleShape_setFillColor(particle->shape, particle->color);
    }
    if (particle->color.a <= 0) {
        engine->particles = delete_particle(engine, particle);
        fuel_engine(engine, 1);
    }
}

void draw_particles(sfRenderWindow *window, particle_engine_t *engine)
{
    particle_t *data = NULL;

    for (node_t *node = engine->particles; node != NULL; node = node->next) {
        data = node->data;
        if (sfClock_getElapsedTime(data->delay_clock).microseconds >
        data->delay) {
            sfClock_restart(data->delay_clock);
            data->prev_pos = sfCircleShape_getPosition(data->shape);
            handle_dissolve(engine, data);
            add_gravity(engine, data);
            sfCircleShape_move(data->shape, data->velocity);
        }
        handle_trace(engine, data, window);
        sfRenderWindow_drawCircleShape(window, data->shape, NULL);
    }
}
