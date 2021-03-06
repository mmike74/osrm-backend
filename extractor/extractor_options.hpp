/*

Copyright (c) 2015, Project OSRM contributors
All rights reserved.

Redistribution and use in source and binary forms, with or without modification,
are permitted provided that the following conditions are met:

Redistributions of source code must retain the above copyright notice, this list
of conditions and the following disclaimer.
Redistributions in binary form must reproduce the above copyright notice, this
list of conditions and the following disclaimer in the documentation and/or
other materials provided with the distribution.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR
ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
(INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

*/

#ifndef EXTRACTOR_OPTIONS_HPP
#define EXTRACTOR_OPTIONS_HPP

#include <boost/filesystem/path.hpp>

#include <string>

enum class return_code : unsigned
{
    ok,
    fail,
    exit
};

struct ExtractorConfig
{
    ExtractorConfig() noexcept : requested_num_threads(0) {}
    boost::filesystem::path config_file_path;
    boost::filesystem::path input_path;
    boost::filesystem::path profile_path;

    std::string output_file_name;
    std::string restriction_file_name;
    std::string timestamp_file_name;

    unsigned requested_num_threads;
};

struct ExtractorOptions
{
    static return_code ParseArguments(int argc, char *argv[], ExtractorConfig &extractor_config);

    static void GenerateOutputFilesNames(ExtractorConfig &extractor_config);
};

#endif // EXTRACTOR_OPTIONS_HPP
