/*
 * Copyright (c) 2002 Silicon Graphics, Inc.  All Rights Reserved.
 * 
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation; either version 2 of the License, or (at your
 * option) any later version.
 * 
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
 * or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License
 * for more details.
 * 
 * You should have received a copy of the GNU General Public License along
 * with this program; if not, write to the Free Software Foundation, Inc.,
 * 59 Temple Place, Suite 330, Boston, MA  02111-1307 USA
 */

#ifndef _PROXY_H
#define _PROXY_H

#include "pmapi.h"
#include "impl.h"

/* The table of clients, used by pmproxy */
typedef struct {
    int			fd;		/* client socket descriptor */
    int			version;	/* proxy-client protocol version */
    struct sockaddr_in	addr;		/* address of client */
    struct {				/* Status of connection to client */
	unsigned int	connected : 1;	/* Client connected */
    } status;
    char		*pmcd_hostname;	/* PMCD hostname */
    int			pmcd_port;	/* PMCD port */
    int			pmcd_fd;	/* PMCD socket descriptor */
} ClientInfo;

extern ClientInfo	*client;		/* Array of clients */
extern int		nClients;		/* Number of entries in array */
extern int		maxSockFd;		/* largest fd for a clients
						 * and pmcd connections */
extern fd_set		sockFds;		/* for select() */

/* prototypes */
extern ClientInfo *AcceptNewClient(int);
extern void DeleteClient(ClientInfo *);

extern int	maxReqPortFd;	/* highest request port file descriptor */

#endif /* _PROXY_H */
