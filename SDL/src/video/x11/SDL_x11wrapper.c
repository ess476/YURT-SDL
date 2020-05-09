/*
  Simple DirectMedia Layer
  Copyright (C) 1997-2018 Sam Lantinga <slouken@libsdl.org>

  This software is provided 'as-is', without any express or implied
  warranty.  In no event will the authors be held liable for any damages
  arising from the use of this software.

  Permission is granted to anyone to use this software for any purpose,
  including commercial applications, and to alter it and redistribute it
  freely, subject to the following restrictions:

  1. The origin of this software must not be misrepresented; you must not
     claim that you wrote the original software. If you use this software
     in a product, an acknowledgment in the product documentation would be
     appreciated but is not required.
  2. Altered source versions must be plainly marked as such, and must not be
     misrepresented as being the original software.
  3. This notice may not be removed or altered from any source distribution.
*/
#include "../../SDL_internal.h"
#include "SDL_x11wrapper.h"
#include "SDL_syswm.h"

#if SDL_VIDEO_DRIVER_X11

SDL_bool SDL_GetX11WindowInfo(
   SDL_Window* window, SDL_X11Info* x11_info)
{
   SDL_SysWMinfo info;

   if (x11_info == NULL) {
      return SDL_FALSE;
   }

	SDL_VERSION(&info.version);
	if (SDL_GetWindowWMInfo(window, &info) == SDL_FALSE)
	{
		return SDL_FALSE;
	}

   x11_info->display = info.info.x11.display;
   x11_info->window = info.info.x11.window;
   return SDL_TRUE;
}

#endif /* SDL_VIDEO_DRIVER_X11 */

/* vi: set ts=4 sw=4 expandtab: */
