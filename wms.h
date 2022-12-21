/*
 * Watermelon Script
 * Copyright (c) 2022, Keiichi Tabata. All rights reserved.
 */

#ifndef WMS_H
#define WMS_H

#include <stdbool.h>

/*
 * Runtime Structure
 */
struct wms_runtime;

/*
 * Execution
 */

/* Parse script and get runtime. */
struct wms_runtime *wms_make_runtime(const char *script);

/* Get parse error line.  */
int wms_get_parse_error_line(void);

/* Get parse error column. */
int wms_get_parse_error_column(void);

/* Execute main function. */
bool wms_run(struct wms_runtime *rt);

/* Get runtime error line. */
int wms_get_runtime_error_line(struct wms_runtime *rt);

/* Get runtime error message. */
const char *wms_get_runtime_error_message(struct wms_runtime *rt);

/* Cleanup runtime. */
void wms_free_runtime(struct wms_runtime *rt);

/* Must be implemented by main code. */
int wms_printf(const char *s, ...);

/*
 * Foreign Function Interface
 */

#define WMSAPI

/* Argument type. */
struct wms_value;

/* Pointer to foreign function. */
typedef bool WMSAPI (*wms_ffi_func_ptr)(struct wms_runtime *rt, struct wms_value *arg);

/* Register foreign function. */
bool wms_register_ffi_func(struct wms_runtime *rt, const char *name, wms_ffi_func_ptr func);

/* Get value for key from foreign function argument.  */
const char *wms_get_ffi_arg_value(struct wms_runtime *rt, struct wms_value *arg, const char *key);

/* Set value for key to foreign function argument.  */
bool wms_set_ffi_arg_value(struct wms_runtime *rt, struct wms_value *arg, const char *key, const char *val);

#endif
