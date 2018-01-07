#include "animation-cycle.hpp"

class AnimationRandomCycle: public AnimationCycle {
public:
    Animation* get_next_animation() override;
private:
    Animation* generate_new_animation();
    const Ring_t& get_random_color();

    int color_index_;
};