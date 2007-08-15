/*
Copyright (C) 2004-2006 Grame  

This program is free software; you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation; either version 2 of the License, or
  (at your option) any later version.

  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with this program; if not, write to the Free Software
  Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.

*/

#ifndef __JackLibClient__
#define __JackLibClient__

#include "JackClient.h"
#include "JackShmMem.h"
#include "JackClientControl.h"
#include "JackEngineControl.h"

namespace Jack
{

/*!
\brief Client on the library side.
*/

class JackLibClient : public JackClient
{

    private:

        JackShmReadWritePtr1<JackClientControl>	fClientControl;	/*! Shared client control */

    public:

        JackLibClient(JackSynchro** table);
        virtual ~JackLibClient();

        int Open(const char* name, jack_options_t options, jack_status_t* status);

        int ClientNotifyImp(int refnum, const char* name, int notify, int sync, int value);

        JackGraphManager* GetGraphManager() const;
        JackEngineControl* GetEngineControl() const;
        JackClientControl* GetClientControl() const;
};


} // end of namespace

#endif

