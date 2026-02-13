/**
 * @file E_Desktop_C_Sloder_gen.c
 */

/*********************
 *      INCLUDES
 *********************/

#include "E_Desktop_C_Sloder_gen.h"

#if LV_USE_XML
#endif /* LV_USE_XML */

/*********************
 *      DEFINES
 *********************/

/**********************
 *      TYPEDEFS
 **********************/

/**********************
 *  STATIC PROTOTYPES
 **********************/

/**********************
 *  STATIC VARIABLES
 **********************/

/*----------------
 * Translations
 *----------------*/

/**********************
 *  GLOBAL VARIABLES
 **********************/

/*--------------------
 *  Permanent screens
 *-------------------*/

/*----------------
 * Global styles
 *----------------*/

/*----------------
 * Fonts
 *----------------*/

/*----------------
 * Images
 *----------------*/

const void * bootSkinImg;

/*----------------
 * Subjects
 *----------------*/

/**********************
 *      MACROS
 **********************/

/**********************
 *   GLOBAL FUNCTIONS
 **********************/

void E_Desktop_C_Sloder_init_gen(const char * asset_path)
{
    char buf[256];

    /*----------------
     * Global styles
     *----------------*/

    /*----------------
     * Fonts
     *----------------*/


    /*----------------
     * Images
     *----------------*/
    lv_snprintf(buf, 256, "%s%s", asset_path, "./images/bootSkinImg.png");
    bootSkinImg = lv_strdup(buf);

    /*----------------
     * Subjects
     *----------------*/
    /*----------------
     * Translations
     *----------------*/

#if LV_USE_XML
    /* Register widgets */

    /* Register fonts */

    /* Register subjects */

    /* Register callbacks */
#endif

    /* Register all the global assets so that they won't be created again when globals.xml is parsed.
     * While running in the editor skip this step to update the preview when the XML changes */
#if LV_USE_XML && !defined(LV_EDITOR_PREVIEW)
    /* Register images */
    lv_xml_register_image(NULL, "bootSkinImg", bootSkinImg);
#endif

#if LV_USE_XML == 0
    /*--------------------
     *  Permanent screens
     *-------------------*/
    /* If XML is enabled it's assumed that the permanent screens are created
     * manaully from XML using lv_xml_create() */
#endif
}

/* Callbacks */

/**********************
 *   STATIC FUNCTIONS
 **********************/