// License       : License.txt
// Specifications: Spec-TC1046.pdf
/*-- File Header Comment Start -----------------------------------------------*/
// File Name        : TC1046.h
// Reason for change: 01.00.00 : 13/10/'22 : New Release
// Nickname         : Blue Dragon
/*-- File Header Comment End -------------------------------------------------*/

#ifndef __TC1046_H__
#define __TC1046_H__

#include "user_define.h"

// Components number
#define iTC1046                 116U                    // Microchip Technology TC1046

// MCP9700 System Parts definitions
#define iTC1046_xoff            0.424F                  // X offset [V]
#define iTC1046_yoff            0.0F                    // Y offset [degree celsius]
#define iTC1046_gain            0.00625F                // Gain [V/degree celsius]
#define iTC1046_max             125.0F                  // Temperature Max [degree celsius]
#define iTC1046_min             -40.0F                  // Temperature Min [degree celsius]

extern const tbl_adc_t tbl_TC1046;

#endif /*__TC1046_H__*/
