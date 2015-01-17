#ifndef _CSLAM_BRUTE_FORCE_MATCHER_
#define _CSLAM_BRUTE_FORCE_MATCHER_

#include <boost/shared_ptr.hpp>
#include <boost/scoped_ptr.hpp>

#include <opencv2/opencv.hpp>

#include <registration/Registrator5P.h>
#include <registration/RegistratorBAPTAM.h>
#include <ptam/KeyFrame.h>

namespace backend {

class BruteForceMatcher {
public:
    BruteForceMatcher(const cs_geom::Camera * cam, int camNum);

    boost::shared_ptr<ptam::Edge> tryAndMatch(const ptam::KeyFrame& kf1, const ptam::KeyFrame& kf2);

protected:
    boost::scoped_ptr<cv::DescriptorMatcher> matcher_;
    boost::scoped_ptr<Registrator5P>     reg_5p_;
    boost::scoped_ptr<RegistratorBAPTAM> reg_ba_;
};

}

#endif /* _CSLAM_BRUTE_FORCE_MATCHER_ */
