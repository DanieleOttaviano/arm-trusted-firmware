/*
 * Copyright (c) 2014-2016, ARM Limited and Contributors. All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * Redistributions of source code must retain the above copyright notice, this
 * list of conditions and the following disclaimer.
 *
 * Redistributions in binary form must reproduce the above copyright notice,
 * this list of conditions and the following disclaimer in the documentation
 * and/or other materials provided with the distribution.
 *
 * Neither the name of ARM nor the names of its contributors may be used
 * to endorse or promote products derived from this software without specific
 * prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 */

#ifndef __ZYNQMP_PRIVATE_H__
#define __ZYNQMP_PRIVATE_H__

#include <interrupt_mgmt.h>
#include <bl_common.h>

void zynqmp_config_setup(void);

/* ZynqMP specific functions */
unsigned int zynqmp_get_uart_clk(void);
unsigned int zynqmp_get_bootmode(void);

#if ZYNQMP_WARM_RESTART
/*
 * Register handler to specific GIC entrance
 * for INTR_TYPE_EL3 type of interrupt
 */
int request_intr_type_el3(uint32_t, interrupt_type_handler_t);
#endif

/* For FSBL handover */
enum fsbl_handoff {
	FSBL_HANDOFF_SUCCESS = 0,
	FSBL_HANDOFF_NO_STRUCT,
	FSBL_HANDOFF_INVAL_STRUCT,
	FSBL_HANDOFF_TOO_MANY_PARTS,
};

enum fsbl_handoff fsbl_atf_handover(entry_point_info_t *bl32_image_ep_info,
		       entry_point_info_t *bl33_image_ep_info);

#endif /* __ZYNQMP_PRIVATE_H__ */
