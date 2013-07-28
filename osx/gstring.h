//	GString.h
//
//	G-lib replacement for OS X
//
//	Created by Aaron Burghardt 7/25/2013.
//	Copyright 2013 Aaron Burghardt. All rights reserved.
//	g_string_append_c(GString *string, char c);

// g_string_new(app_path);
// g_string_free(payload, TRUE);
// g_string_prepend(packet, ",");
// g_string_append_len(in_queue, buf, received);
// g_string_erase(in_queue, 0, in_queue->str - pkg_end);


typedef char gchar;
typedef unsigned int guint;
typedef signed long gssize;
typedef unsigned long gsize;
typedef int gboolean;
typedef char gunichar;

typedef struct GString {
	gchar  *str;
	gsize len;
	gsize allocated_len;
	//	CFMutableStringRef cf_string;
} GString;

#define false (0)
#define true  (1)

GString * g_string_new(const gchar *init);

GString * g_string_new_len(const gchar *init, gssize len);

GString * g_string_sized_new(gsize dfl_size);

GString * g_string_assign(GString *string, const gchar *rval);

#define	g_string_sprintf
#define	g_string_sprintfa

void g_string_vprintf(GString *string, const gchar *format, va_list args);

void g_string_append_vprintf(GString *string, const gchar *format, va_list args);

void g_string_printf(GString *string, const gchar *format, ...);

void g_string_append_printf(GString *string, const gchar *format, ...);

GString * g_string_append(GString *string, const gchar *val);

GString * g_string_append_c(GString *string, gchar c);

GString * g_string_append_unichar(GString *string, gunichar wc);

GString * g_string_append_len(GString *string, const gchar *val, gssize len);

GString * g_string_append_uri_escaped(GString *string, const char *unescaped, const char *reserved_chars_allowed, gboolean allow_utf8);

GString * g_string_prepend(GString *string, const gchar *val);

GString * g_string_prepend_c(GString *string, gchar c);

GString * g_string_prepend_unichar(GString *string, gunichar wc);

GString * g_string_prepend_len(GString *string, const gchar *val, gssize len);

GString * g_string_insert(GString *string, gssize pos, const gchar *val);

GString * g_string_insert_c(GString *string, gssize pos, gchar c);

GString * g_string_insert_unichar(GString *string, gssize pos, gunichar wc);

GString * g_string_insert_len(GString *string, gssize pos, const gchar *val, gssize len);

GString * g_string_overwrite(GString *string, gsize pos, const gchar *val);

GString * g_string_overwrite_len(GString *string, gsize pos, const gchar *val, gssize len);

GString * g_string_erase(GString *string, gssize pos, gssize len);

GString * g_string_truncate(GString *string, gsize len);

GString * g_string_set_size(GString *string, gsize len);

gchar * g_string_free(GString *string, gboolean free_segment);

GString * g_string_up(GString *string);

GString * g_string_down(GString *string);

guint g_string_hash(const GString *str);

gboolean g_string_equal(const GString *v, const GString *v2);
