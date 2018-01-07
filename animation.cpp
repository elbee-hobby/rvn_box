#include "animation.hpp"

Animation::Animation()
    : next_(nullptr)
{}

Animation::~Animation() {
    if (next_ != nullptr) {
        delete next_;
    }
}

Animation* Animation::next(){
    return next_;
}

void Animation::set_next(Animation *next) {
    next->next_ = next_;
    next_ = next;
}
