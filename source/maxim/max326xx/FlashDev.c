/* CMSIS-DAP Interface Firmware
 * Copyright (c) 2009-2013 ARM Limited
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include "FlashOS.h"

#define FLASH_DRV_VERS (0x100+VERS)   // Driver Version, do not modify!

#if (TARGET_MXM == 32630)
struct FlashDevice const FlashDevice  =  {
   FLASH_DRV_VERS,             // Driver Version, do not modify!
   "Maxim MAX32xxx Flash",     // Device Name
   ONCHIP,                     // Device Type
   0x00000000,                 // Device Start Address
   0x00200000,                 // Device Size
   0x00002000,                 // Programming Page Size
   0,                          // Reserved, must be 0
   0xFF,                       // Initial Content of Erased Memory
   100,                        // Program Page Timeout 100 mSec
   3000,                       // Erase Sector Timeout 3000 mSec

   // Specify Size and Address of Sectors
   0x00002000, 0x00000000,     // Sector Size 8kB
   SECTOR_END
};
#elif (TARGET_MXM == 32665)
struct FlashDevice const FlashDevice = {
    FLASH_DRV_VERS,             // Driver Version, do not modify!
    "Maxim MAX32xxx Flash",     // Device Name
    ONCHIP,                     // Device Type
    0x10000000,                 // Device Start Address
    0x00100000,                 // Device Size
    0x00002000,                 // Programming Page Size
    0,                          // Reserved, must be 0
    0xFF,                       // Initial Content of Erased Memory
    100,                        // Program Page Timeout 100 mSec
    3000,                       // Erase Sector Timeout 3000 mSec

    // Specify Size and Address of Sectors
    {{0x00002000, 0x00000000},  // Sector Size {8kB, starting at address 0}
    {SECTOR_END}}
};
#elif (TARGET_MXM == 32670)
struct FlashDevice const FlashDevice = {
    FLASH_DRV_VERS,             // Driver Version, do not modify!
    "Maxim MAX32xxx Flash",     // Device Name
    ONCHIP,                     // Device Type
    0x10000000,                 // Device Start Address
    0x60000,                    // Device Size
    0x2000,                     // Programming Page Size
    0,                          // Reserved, must be 0
    0xFF,                       // Initial Content of Erased Memory
    100,                        // Program Page Timeout 100 mSec
    3000,                       // Erase Sector Timeout 3000 mSec

    // Specify Size and Address of Sectors
    {{0x00002000, 0x00000000},  // Sector Size {8kB, starting at address 0}
    {SECTOR_END}}
};
#elif (TARGET_MXM == 32650)
struct FlashDevice const FlashDevice = {
    FLASH_DRV_VERS,             // Driver Version, do not modify!
    "Maxim MAX32xxx Flash",     // Device Name
    ONCHIP,                     // Device Type
    0x10000000,                 // Device Start Address
    0x300000,                    // Device Size
    0x4000,                     // Programming Page Size
    0,                          // Reserved, must be 0
    0xFF,                       // Initial Content of Erased Memory
    200,                        // Program Page Timeout 200 mSec
    5000,                       // Erase Sector Timeout 5000 mSec

    // Specify Size and Address of Sectors
    {{0x00004000, 0x00000000},  // Sector Size {16kB, starting at address 0}
    {SECTOR_END}}
};
#else
#error TARGET NOT DEFINED. Define TARGET as a preprocessor symbol.
#endif
