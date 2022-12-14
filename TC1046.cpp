// License       : License.txt
// Specifications: Spec-TC1046.pdf
/*-- File Header Comment Start -----------------------------------------------*/
// File Name        : TC1046.cpp
// Reason for change: 01.00.00 : 13/10/'22 : New Release
// Nickname         : Blue Dragon
/*-- File Header Comment End -------------------------------------------------*/

#include        "TC1046.h"

#if     iTC1046_ma == iSMA                              // Simple moving average filter
static float32 TC1046_sma_buf[iTC1046_SMA_num];
static sma_f32_t TC1046_Phy_SMA =
{
        iInitial ,                                      // Initial state
        iTC1046_SMA_num ,                               // Simple moving average number & buf size
        0U ,                                            // buffer position
        0.0F ,                                          // sum
        &TC1046_sma_buf[0]                              // buffer
};

#elif   iTC1046_ma == iEMA                              // Exponential moving average filter
static ema_f32_t TC1046_Phy_EMA =
{
        iInitial ,                                      // Initial state
        0.0F ,                                          // Xn-1
        iTC1046_EMA_K                                   // Exponential smoothing factor
};

#elif   iTC1046_ma == iWMA                              // Weighted moving average filter
static float32 TC1046_wma_buf[iTC1046_WMA_num];
static wma_f32_t TC1046_Phy_WMA =
{
        iInitial ,                                      // Initial state
        iTC1046_WMA_num ,                               // Weighted moving average number & buf size
        0U ,                                            // buffer poition
        iTC1046_WMA_num * (iTC1046_WMA_num + 1)/2 ,     // kn sum
        &TC1046_wma_buf[0]                              // Xn buffer
};

#else                                                   // Non-moving average filter
#endif

#define iDummy_adr       0xffffffff                     // Dummy address

const tbl_adc_t tbl_TC1046 =
{
        iTC1046                 ,
        iTC1046_pin             ,
        iTC1046_xoff            ,
        iTC1046_yoff            ,
        iTC1046_gain            ,
        iTC1046_max             ,
        iTC1046_min             ,
        iTC1046_ma              ,
        
#if     iTC1046_ma == iSMA                              // Simple moving average filter
        &TC1046_Phy_SMA         ,
        (ema_f32_t*)iDummy_adr  ,
        (wma_f32_t*)iDummy_adr
#elif   iTC1046_ma == iEMA                              // Exponential moving average filter
        (sma_f32_t*)iDummy_adr  ,
        &TC1046_Phy_EMA         ,
        (wma_f32_t*)iDummy_adr
#elif   iTC1046_ma == iWMA                              // Weighted moving average filter
        (sma_f32_t*)iDummy_adr  ,
        (ema_f32_t*)iDummy_adr  ,
        &TC1046_Phy_WMA
#else                                                   // Non-moving average filter
        (sma_f32_t*)iDummy_adr  ,
        (ema_f32_t*)iDummy_adr  ,
        (wma_f32_t*)iDummy_adr
#endif

};
