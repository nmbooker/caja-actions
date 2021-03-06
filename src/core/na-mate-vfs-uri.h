/*
 * Caja-Actions
 * A Caja extension which offers configurable context menu actions.
 *
 * Copyright (C) 2005 The MATE Foundation
 * Copyright (C) 2006-2008 Frederic Ruaudel and others (see AUTHORS)
 * Copyright (C) 2009-2012 Pierre Wieser and others (see AUTHORS)
 *
 * Caja-Actions is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General  Public  License  as
 * published by the Free Software Foundation; either  version  2  of
 * the License, or (at your option) any later version.
 *
 * Caja-Actions is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even  the  implied  warranty  of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See  the  GNU
 * General Public License for more details.
 *
 * You should have received a copy of the GNU General Public  License
 * along with Caja-Actions; see the file  COPYING.  If  not,  see
 * <http://www.gnu.org/licenses/>.
 *
 * Authors:
 *   Frederic Ruaudel <grumz@grumz.net>
 *   Rodrigo Moya <rodrigo@mate-db.org>
 *   Pierre Wieser <pwieser@trychlos.org>
 *   ... and many others (see AUTHORS)
 */

#ifndef __CAJA_ACTIONS_NA_PRIVATE_MATE_VFS_URI_H__
#define __CAJA_ACTIONS_NA_PRIVATE_MATE_VFS_URI_H__

/*
 * pwi 2009-07-29
 * shamelessly pull out of MateVFS (mate-vfs-uri and consorts)
 */

/* mate-vfs-uri.h - URI handling for the MATE Virtual File System.

   Copyright (C) 1999 Free Software Foundation

   The Mate Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Library General Public License as
   published by the Free Software Foundation; either version 2 of the
   License, or (at your option) any later version.

   The Mate Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Library General Public License for more details.

   You should have received a copy of the GNU Library General Public
   License along with the Mate Library; see the file COPYING.LIB.  If not,
   write to the Free Software Foundation, Inc., 59 Temple Place - Suite 330,
   Boston, MA 02111-1307, USA.

   Author: Ettore Perazzoli <ettore@comm2000.it> */

#include <glib.h>

G_BEGIN_DECLS

typedef struct {
	gchar *path;
	gchar *scheme;
	gchar *host_name;
	guint  host_port;
	gchar *user_name;
	gchar *password;
}
	NAMateVFSURI;

/*
 * MATE_VFS_URI_MAGIC_CHR:
 *
 * The character used to divide location from
 * extra "arguments" passed to the method.
 **/
/*
 * MATE_VFS_URI_MAGIC_STR:
 *
 * The character used to divide location from
 * extra "arguments" passed to the method.
 **/
#define MATE_VFS_URI_MAGIC_CHR	'#'
#define MATE_VFS_URI_MAGIC_STR "#"

/*
 * MATE_VFS_URI_PATH_CHR:
 *
 * Defines the path seperator character.
 **/
/*
 * MATE_VFS_URI_PATH_STR:
 *
 * Defines the path seperator string.
 **/
#define MATE_VFS_URI_PATH_CHR '/'
#define MATE_VFS_URI_PATH_STR "/"

void na_mate_vfs_uri_parse( NAMateVFSURI *vfs, const gchar *uri );

void na_mate_vfs_uri_free( NAMateVFSURI *vfs );

G_END_DECLS

#endif /* __CAJA_ACTIONS_NA_PRIVATE_MATE_VFS_URI_H__ */
