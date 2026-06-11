// Based on upstream's test-packaging/example.cpp: create a temporary file,
// scatter-write to it, read it back, and verify the content. The i/o goes
// through non-inline compiled symbols, proving the library's symbol
// export/import macro setup.
//
#include <llfio/llfio.hpp>

#include <cstring>
#include <iostream>

int main ()
{
  namespace llfio = LLFIO_V2_NAMESPACE;

  auto r = [] () -> llfio::result<int>
  {
    OUTCOME_TRY (auto &&fh, llfio::file_handle::temp_file ());

    static const char *buffers[] = {"He", "llo", " world"};
    OUTCOME_TRY (fh.write (0,
                           {{(const llfio::byte *) buffers[0], 2},
                            {(const llfio::byte *) buffers[1], 3},
                            {(const llfio::byte *) buffers[2], 6}}));

    llfio::byte buffer[64];
    OUTCOME_TRY (auto &&read, fh.read (0, {{buffer, sizeof (buffer)}}));

    if (read != 11)
    {
      std::cerr << "FAILURE: Did not read 11 bytes!" << std::endl;
      return 1;
    }

    if (0 != memcmp (buffer, "Hello world", 11))
    {
      std::cerr << "FAILURE: Did not read what was written!" << std::endl;
      return 1;
    }

    return 0;
  } ();

  if (!r)
  {
    std::cerr << "ERROR: " << r.error ().message ().c_str () << std::endl;
    return 1;
  }

  return r.value ();
}
