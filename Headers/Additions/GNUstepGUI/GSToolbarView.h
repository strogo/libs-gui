/* 
   <title>GSToolbarView.h</title>

   <abstract>The private toolbar class which draws the actual toolbar.</abstract>
   
   Copyright (C) 2002 Free Software Foundation, Inc.

   Author:  Gregory John Casamento <greg_casamento@yahoo.com>,
            Fabien Vallon <fabien.vallon@fr.alcove.com>,
	    Quentin Mathe <qmathe@club-internet.fr>
   Date: May 2002
   
   This file is part of the GNUstep GUI Library.

   This library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Library General Public
   License as published by the Free Software Foundation; either
   version 2 of the License, or (at your option) any later version.
   
   This library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Library General Public License for more details.

   You should have received a copy of the GNU Library General Public
   License along with this library; see the file COPYING.LIB.
   If not, write to the Free Software Foundation,
   59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.
*/ 

#ifndef _GSToolbarView_h_INCLUDE
#define _GSToolbarView_h_INCLUDE

#include <Foundation/NSObject.h>
#include <Foundation/NSGeometry.h>
#include <AppKit/NSView.h>

#include "GNUstepGUI/GSToolbar.h"
// Necessary for NSToolbarDisplayMode and NSToolbarSizeMode

@class NSMutableArray;
@class NSToolbarItem;
@class NSClipView;
@class GSToolbarClippedItemsButton;

enum {
  GSToolbarViewNoBorder = 0,
  GSToolbarViewRightBorder = 2,
  GSToolbarViewLeftBorder = 4,
  GSToolbarViewTopBorder = 8,
  GSToolbarViewBottomBorder = 16
};

typedef enum {
  _ToolbarViewDefaultHeight = 61,
  _ToolbarViewRegularHeight = 61,
  _ToolbarViewSmallHeight = 51
} _ToolbarViewHeight;

typedef enum {
  _ItemBackViewDefaultHeight = 60,
  _ItemBackViewRegularHeight = 60,
  _ItemBackViewSmallHeight = 50
} _ItemBackViewHeight;

typedef enum {
  _ItemBackViewDefaultWidth = 60,
  _ItemBackViewRegularWidth = 60,
  _ItemBackViewSmallWidth = 50
} _ItemBackViewWidth;

static const int _ItemBackViewX = 0;
static const int _ItemBackViewY = 0;
static const int _InsetItemViewX = 10;
static const int _InsetItemViewY = 26;
static const int _InsetItemTextX = 3;
static const int _InsetItemTextY = 4;

static const int _ClippedItemsViewWidth = 28;

@interface GSToolbarView : NSView
{
  GSToolbar *_toolbar;
  NSClipView *_clipView, *_clipViewForEditMode;
  GSToolbarClippedItemsButton *_clippedItemsMark;
  NSMutableArray *_visibleBackViews;
  BOOL _willBeVisible;
  unsigned int _borderMask;
  NSToolbarDisplayMode _displayMode;
  NSToolbarSizeMode _sizeMode;
  unsigned int _heightFromLayout;
}

- (id) initWithFrame: (NSRect)frame;
- (id) initWithFrame: (NSRect)frame 
         displayMode: (NSToolbarDisplayMode)displayMode 
	    sizeMode: (NSToolbarSizeMode)sizeMode; 

// Accessors
- (GSToolbar *) toolbar;
- (void) setToolbar: (GSToolbar *)toolbar;
- (unsigned int) borderMask;
- (void) setBorderMask: (unsigned int)borderMask;

@end

#endif
