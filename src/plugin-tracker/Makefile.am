# Caja-Actions
# A Caja extension which offers configurable context menu actions.
#
# Copyright (C) 2005 The MATE Foundation
# Copyright (C) 2006-2008 Frederic Ruaudel and others (see AUTHORS)
# Copyright (C) 2009-2012 Pierre Wieser and others (see AUTHORS)
#
# Caja-Actions is free software; you can redistribute it and/or
# modify it under the terms of the GNU General  Public  License  as
# published by the Free Software Foundation; either  version  2  of
# the License, or (at your option) any later version.
#
# Caja-Actions is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even  the  implied  warranty  of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See  the  GNU
# General Public License for more details.
#
# You should have received a copy of the GNU General Public  License
# along with Caja-Actions; see the file  COPYING.  If  not,  see
# <http://www.gnu.org/licenses/>.
#
# Authors:
#   Frederic Ruaudel <grumz@grumz.net>
#   Rodrigo Moya <rodrigo@mate-db.org>
#   Pierre Wieser <pwieser@trychlos.org>
#   ... and many others (see AUTHORS)

AM_CPPFLAGS += \
	-I $(top_srcdir)											\
	-I $(top_srcdir)/src										\
	-DG_LOG_DOMAIN=\"${NA_LOGDOMAIN_PLUGIN_TRACKER}\"			\
	$(CAJA_ACTIONS_CFLAGS)									\
	$(NULL)

caja_extensiondir = $(CAJA_EXTENSIONS_DIR)

caja_extension_LTLIBRARIES = libcaja-actions-tracker.la

BUILT_SOURCES =

if HAVE_GDBUS
BUILT_SOURCES += \
	na-tracker-gdbus.c											\
	na-tracker-gdbus.h											\
	$(NULL)

na-tracker-gdbus.c na-tracker-gdbus.h: na-tracker-gdbus.xml
	gdbus-codegen \
		--interface-prefix org.caja_actions.DBus.Tracker.	\
		--generate-c-code na-tracker-gdbus						\
		--c-namespace NA_Tracker								\
		--c-generate-object-manager								\
		--generate-docbook na-tracker-gdbus-docs				\
		$<

DISTCLEANFILES = \
	na-tracker-gdbus-docs-org.caja_actions.DBus.Tracker.Properties1.xml
endif

if HAVE_DBUS_GLIB
BUILT_SOURCES += \
	na-tracker-dbus-glib.h										\
	$(NULL)

na-tracker-dbus-glib.h: na-tracker-dbus-glib.xml
	dbus-binding-tool --mode=glib-server --prefix=na_tracker_dbus $< > $@
endif

nodist_libcaja_actions_tracker_la_SOURCES = \
	$(BUILT_SOURCES)											\
	$(NULL)

libcaja_actions_tracker_la_SOURCES = \
	na-tracker.c												\
	na-tracker.h												\
	na-tracker-plugin.c											\
	$(NULL)

libcaja_actions_tracker_la_LIBADD = \
	$(top_builddir)/src/core/libna-core.la						\
	$(CAJA_ACTIONS_LIBS)									\
	$(NULL)

libcaja_actions_tracker_la_LDFLAGS = \
	-module 													\
	-no-undefined												\
	-avoid-version												\
	$(NULL)

EXTRA_DIST = \
	na-tracker-dbus-glib.xml									\
	na-tracker-gdbus.xml										\
	$(NULL)

CLEANFILES = \
	$(BUILT_SOURCES)											\
	$(NULL)
