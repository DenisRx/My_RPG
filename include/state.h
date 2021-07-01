/*
** EPITECH PROJECT, 2020
** my_owl
** File description:
** state
*/

#ifndef STATE_H_
#define STATE_H_

typedef enum states {
    BLANK,
    START_MENU,
    OPTIONS_MENU,
    HTP_MENU,
    GAME,
    PAUSE
} STATE;

#define START_PRESSED 1
#define EXIT_PRESSED -1

#endif /* !STATE_H_ */