# Omi C++ Protocol Statistics

[![Omi](https://github.com/Open-Markets-Initiative/Directory/blob/main/About/Images/Logo.png)](https://github.com/Open-Markets-Initiative/Directory)

Omi C++ protocol statistics provide generated pcap-based binary protocol validation tools for common exchange protocols.

Each protocol generates a standalone C++ project that reads pcap files and reports message statistics.

## Protocols

| Organization | Protocol |
| --- | --- |
| Securities Industry Automation Corporation | Opra Binary Interface 6.1 |
| Investors Exchange | Investors Exchange Transport Protocol 1.0.1 |
| National Association of Securities Dealers Automated Quotations | Itch 5.0 |
| Chicago Mercantile Exchange | Simple Binary Encoding 1.13 |

## Build

Requirements: C++23, CMake 3.28+

```bash
mkdir build && cd build
cmake ..
make
```

## Usage

```bash
./<target> --input <pcap file>
```

Run with `--help` for all options.

## Development

This entire repository is source generated. If you wish to suggest updates, the recommended process is to create an issue with changes and explanation. Time permitting, we will update the models and regenerate.

## Open Markets Initiative

The [Open Markets Initiative (Omi)](https://github.com/Open-Markets-Initiative/Directory) is a group of technologists dedicated to enhancing the stability of electronic financial markets using modern development methods.

For a list of Omi projects: [Omi Directory](https://github.com/Open-Markets-Initiative/Directory/tree/main/Projects)

## Disclaimer

Any similarities between existing people, places and/or protocols is purely incidental.

Enjoy.
