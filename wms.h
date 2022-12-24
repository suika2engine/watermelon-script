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

/* Must be implemented by the main code. */
int wms_printf(const char *s, ...);

/*
 * Foreign Function Interface
 */

/* Value type. */
struct wms_value;

/* Pointer to foreign function. */
typedef bool (*wms_ffi_func_ptr)(struct wms_runtime *rt);

/* FFI function table. */
struct wms_ffi_func_tbl {
	wms_ffi_func_ptr func_ptr;
	const char *func_name;
	const char *param_name[16];
};

/* Register a foreign function. */
bool wms_register_ffi_func_tbl(struct wms_runtime *rt, struct wms_ffi_func_tbl *ffi_func_tbl, int count);

/* Get the argument of an FFI function. */
struct wms_value *wms_get_argument(struct wms_runtime *rt, const char *param_name);

/* Get the type of `struct wms_value`. */
bool wms_is_int(struct wms_runtime *rt, struct wms_value *val);
bool wms_is_float(struct wms_runtime *rt, struct wms_value *val);
bool wms_is_str(struct wms_runtime *rt, struct wms_value *val);
bool wms_is_array(struct wms_runtime *rt, struct wms_value *val);

/* Get the value of `struct wms_value`. */
bool wms_get_int_value(struct wms_runtime *rt, struct wms_value *val, int *ret);
bool wms_get_float_value(struct wms_runtime *rt, struct wms_value *val, double *ret);
bool wms_get_str_value(struct wms_runtime *rt, struct wms_value *val, const char **ret);
struct wms_value *wms_get_array_element_by_int(struct wms_runtime *rt, struct wms_value *val, int key);
struct wms_value *wms_get_array_element_by_float(struct wms_runtime *rt, struct wms_value *val, double key);
struct wms_value *wms_get_array_element_by_str(struct wms_runtime *rt, struct wms_value *val, const char *key);

/* Set the return value. */
bool wms_set_int_return_value(struct wms_runtime *rt, int val);
bool wms_set_float_return_value(struct wms_runtime *rt, double val);
bool wms_set_str_return_value(struct wms_runtime *rt, const char *val);
bool wms_set_array_return_value(struct wms_runtime *rt, const char *key, const char *val);

#endif
