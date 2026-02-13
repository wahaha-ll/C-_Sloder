/**
 * @file mainScreen_gen.h
 */

#ifndef MAINSCREEN_H
#define MAINSCREEN_H

#ifdef __cplusplus
extern "C" {
#endif

/*********************
 *      INCLUDES
 *********************/

#ifdef LV_LVGL_H_INCLUDE_SIMPLE
    #include "lvgl.h"
#else
    #include "lvgl/lvgl.h"
#endif

/*********************
 *      DEFINES
 *********************/

/**********************
 *      TYPEDEFS
 **********************/

/**********************
 * GLOBAL PROTOTYPES
 **********************/



lv_obj_t * mainScreen_create(void);

/**********************
 *      MACROS
 **********************/

#ifdef __cplusplus
} /*extern "C"*/
#endif

#endif /*MAINSCREEN_H*/