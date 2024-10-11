#ifndef FGSERVER_H
#define FGSERVER_H

#include <godot_cpp/classes/node.hpp>

namespace godot {

class FGServer : public Node {
  GDCLASS(FGServer, Node)

private:
  double time_passed;

protected:
  static void _bind_methods();

public:
  FGServer();
  ~FGServer();

  void enter();
  // void step(int inputs[]);

  // void _physics_process(double_t delta) override;
  void _process(double delta) override;
  void _ready() override;
};

} // namespace godot

#endif
