#pragma once

#include "ofxUndo.h"
#include "ofxUndoHistoryInterface.h"

namespace ofx { namespace undo {
template<typename Context, typename History>
class Simple : public Manager<Context, History>, public Context
{
public:
	Simple() { ofAddListener(Manager<Context,History>::restoreEvent(), this, &Simple::setValue); }
	~Simple() { ofRemoveListener(Manager<Context,History>::restoreEvent(), this, &Simple::setValue); }
	void store() { Manager<Context, History>::store(static_cast<Context&>(*this)); };
private:
	void setValue(Context &c) { static_cast<Context&>(*this) = c; }
};
}}
template<typename Context, typename History=ofx::undo::history::Vector<Context>>
using ofxUndo = ofx::undo::Simple<Context, History>;
