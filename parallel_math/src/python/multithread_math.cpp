//
// Created by Santiago Hurtado on 02.11.19.
//
#include "multithread/NaturalNumbers.h"
#include "multithread/Vectors.h"
#include <vector>
#define BOOST_PYTHON_STATIC_LIB

#include <boost/python.hpp>

BOOST_PYTHON_MODULE (multithread_math) {
        boost::python::class_<multithread::NaturalNumbers>("NaturalNumbers")
                .def("size",&multithread::NaturalNumbers::size)
                .def("get",&multithread::NaturalNumbers::get)
                .def("calculate_sum_primes",&multithread::NaturalNumbers::calculate_sum_primes)
                .def("results",boost::python::range(&multithread::NaturalNumbers::begin,
                                                    &multithread::NaturalNumbers::end));

        boost::python::class_<multithread::Vectors>("Vectors")
            .def("size",&multithread::Vectors::size)
            .def("get",&multithread::Vectors::get)
            .def("sum",&multithread::Vectors::sum_size)
            .def("results",boost::python::range(&multithread::Vectors::begin,
                                                &multithread::Vectors::end));
}