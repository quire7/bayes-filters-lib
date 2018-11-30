#include <BayesFilters/PFCorrection.h>

using namespace bfl;
using namespace Eigen;


PFCorrection::PFCorrection() noexcept { };


void PFCorrection::correct(const ParticleSet& pred_particles, ParticleSet& cor_particles)
{
    /* Perform correction if required and if measurements can be frozen. */
    if ((!skip_) && getMeasurementModel().freezeMeasurements())
        correctStep(pred_particles, cor_particles);
    else
        cor_particles = pred_particles;
}


bool PFCorrection::skip(const bool status)
{
    skip_ = status;

    return true;
}
