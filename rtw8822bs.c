// SPDX-License-Identifier: GPL-2.0 OR BSD-3-Clause
/* Copyright(c) Jernej Skrabec <jernej.skrabec@gmail.com>
 */

#include <linux/mmc/sdio_func.h>
#include "sdio_ids.h"
#include <linux/module.h>
#include "main.h"
#include "rtw8822b.h"
#include "sdio.h"

static const struct sdio_device_id rtw_8822bs_id_table[] =  {
	{
		SDIO_DEVICE(SDIO_VENDOR_ID_REALTEK,
			    SDIO_DEVICE_ID_REALTEK_RTW8822BS),
		.driver_data = (kernel_ulong_t)&rtw8822b_hw_spec,
	},
	{}
};
MODULE_DEVICE_TABLE(sdio, rtw_8822bs_id_table);

static struct sdio_driver rtw_8822bs_driver = {
	.name = "rtw_8822bs",
	.probe = rtw_sdio_probe,
	.remove = rtw_sdio_remove,
	.id_table = rtw_8822bs_id_table,
	.drv = {
		.pm = &rtw_sdio_pm_ops,
		.shutdown = rtw_sdio_shutdown,
	}
};

static int __init rtw8822bs_init(void)
{
	return sdio_register_driver(&rtw_8822bs_driver);
}

static void __exit rtw8822bs_exit(void)
{
	sdio_unregister_driver(&rtw_8822bs_driver);
}

module_init(rtw8822bs_init);
module_exit(rtw8822bs_exit);

MODULE_AUTHOR("Jernej Skrabec <jernej.skrabec@gmail.com>");
MODULE_DESCRIPTION("Realtek 802.11ac wireless 8822bs driver");
MODULE_LICENSE("Dual BSD/GPL");
