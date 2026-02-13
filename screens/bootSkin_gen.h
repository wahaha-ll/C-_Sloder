/**
 * @file bootSkin_gen.h
 */

#ifndef BOOTSKIN_H
#define BOOTSKIN_H

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

typedef enum {
    BOOTSKIN_TIMELINE_LOADING = 0,
    _BOOTSKIN_TIMELINE_CNT = 1
}bootSkin_timeline_t;

/**********************
 * GLOBAL PROTOTYPES
 **********************/



lv_obj_t * bootSkin_create(void);

/**
 * Get a timeline of a bootSkin
 * @param obj          pointer to a bootSkin component
 * @param timeline_id  ID of the the timeline
 * @return             pointer to the timeline or NULL if not found
 */
lv_anim_timeline_t * bootSkin_get_timeline(lv_obj_t * obj, bootSkin_timeline_t timeline_id);

/**********************
 *      MACROS
 **********************/

#ifdef __cplusplus
} /*extern "C"*/
#endif

#endif /*BOOTSKIN_H*/