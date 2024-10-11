#ifndef FGSERVER_H
#define FGSERVER_H

#include "ggponet.h"
#include <godot_cpp/classes/sprite2d.hpp>

namespace godot
{

    class FGServer : public Sprite2D
    {
        GDCLASS( FGServer, Sprite2D )

    private:
        double time_passed;

    protected:
        static void _bind_methods();

    public:
        FGServer();
        ~FGServer();

        void _process( double delta ) override;
    };

}

#endif
