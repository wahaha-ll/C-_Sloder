/**
 * @file mainScreen_gen.c
 * @brief Template source file for LVGL objects
 */

/*********************
 *      INCLUDES
 *********************/

#include "mainScreen_gen.h"
#include "E_Desktop_C_Sloder.h"

/*********************
 *      DEFINES
 *********************/

/**********************
 *      TYPEDEFS
 **********************/

/***********************
 *  STATIC VARIABLES
 **********************/

/***********************
 *  STATIC PROTOTYPES
 **********************/

/**********************
 *   GLOBAL FUNCTIONS
 **********************/

lv_obj_t * mainScreen_create(void)
{
    LV_TRACE_OBJ_CREATE("begin");


    static bool style_inited = false;

    if (!style_inited) {

        style_inited = true;
    }

    lv_obj_t * lv_obj_0 = lv_obj_create(NULL);
    lv_obj_set_name_static(lv_obj_0, "mainScreen_#");

    lv_obj_t * lv_calendar_0 = lv_calendar_create(lv_obj_0);
    lv_obj_set_x(lv_calendar_0, 0);
    lv_obj_set_y(lv_calendar_0, 0);
    lv_obj_set_width(lv_calendar_0, lv_pct(100));
    lv_obj_set_height(lv_calendar_0, lv_pct(100));

    LV_TRACE_OBJ_CREATE("finished");

    return lv_obj_0;
}

/**********************
 *   STATIC FUNCTIONS
 **********************/

