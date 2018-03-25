//
// PROJECT:         Aspia
// FILE:            codec/decompressor_zlib.h
// LICENSE:         GNU Lesser General Public License 2.1
// PROGRAMMERS:     Dmitry Chapyshev (dmitry@aspia.ru)
//

#ifndef _ASPIA_CODEC__DECOMPRESSOR_ZLIB_H
#define _ASPIA_CODEC__DECOMPRESSOR_ZLIB_H

#include "base/macros.h"
#include "codec/decompressor.h"

#include <zlib.h>

namespace aspia {

class DecompressorZLIB : public Decompressor
{
public:
    DecompressorZLIB();
    ~DecompressorZLIB();

    void reset() override;

    // Decompressor implementations.
    bool process(const uint8_t* input_data,
                 size_t input_size,
                 uint8_t* output_data,
                 size_t output_size,
                 size_t* consumed,
                 size_t* written) override;

private:
    z_stream stream_;

    DISALLOW_COPY_AND_ASSIGN(DecompressorZLIB);
};

} // namespace aspia

#endif // _ASPIA_CODEC__DECOMPRESSOR_ZLIB_H
