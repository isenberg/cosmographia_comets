// This file is part of Cosmographia.
//
// Copyright (C) 2010-2011 Chris Laurel <claurel@gmail.com>
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//    http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#ifndef _ASTRO_TASS17_H_
#define _ASTRO_TASS17_H_

#include <vesta/Trajectory.h>


class TASS17Orbit : public vesta::Trajectory
{
public:
    enum Satellite
    {
        Mimas       = 0,
        Enceladus   = 1,
        Tethys      = 2,
        Dione       = 3,
        Rhea        = 4,
        Titan       = 5,
        Iapetus     = 6,
        Hyperion    = 7,
    };

private:
    TASS17Orbit(Satellite satellite);

public:
    ~TASS17Orbit() {}

    virtual vesta::StateVector state(double tdbSec) const;

    virtual double boundingSphereRadius() const
    {
        return m_boundingRadius;
    }

    virtual bool isPeriodic() const
    {
        return true;
    }

    virtual double period() const
    {
        return m_period;
    }

    static TASS17Orbit* Create(Satellite satellite);

private:
    Satellite m_satellite;
    double m_boundingRadius;
    double m_period;
};

#endif // _ASTRO_TASS17_H_
