#ifndef RED_ARROW_UPDATEABLE_H
#define RED_ARROW_UPDATEABLE_H

namespace ma
{
    class Updateable;
}

class ma::Updateable
{
public:
    virtual void update(float dt) = 0;
};

#endif //RED_ARROW_UPDATEABLE_H
