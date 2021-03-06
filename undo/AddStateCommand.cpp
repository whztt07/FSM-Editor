#include <fsm-editor/undo/AddStateCommand.h>
#include <fsm-editor/fsm-elements/State.h>
#include <fsm-editor/FSMScene.h>

#include <QTransform>

AddStateCommand::AddStateCommand(FSMScene* scene, const QString& name, const QPointF& position)
  : QUndoCommand(QObject::tr("create state %1", "Append to Undo").arg(name))
  , scene_(scene)
  , name_(name)
  , pos_(position)
{}

void AddStateCommand::undo()
{
  scene_->removeState(name_);
}

void AddStateCommand::redo()
{
  FSMScene* copy = scene_;
  scene_->addState(name_, pos_);
}
