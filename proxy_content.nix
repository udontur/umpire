{ fetchurl }: [
  {
    url = "https://github.com/fmtlib/fmt/info/refs?service=git-upload-pack";
    file = fetchurl {
      url = "https://github.com/fmtlib/fmt/info/refs?service=git-upload-pack";
      hash = "sha256-T7cqu0OhaMSQmgs6aeTfWeIazNF4S9v016xVpuGCr68=";
    };
    status_code = 200;
    headers = {
      "content-type" = "application/x-git-upload-pack-advertisement";
    };
  }
  {
    url = "https://github.com/fmtlib/fmt/git-upload-pack";
    file = fetchurl {
      url = "https://github.com/fmtlib/fmt/git-upload-pack";
      hash = "sha256-VfWFMwZZ6RJhz4DMzNCLCPYtDYPKsMWyKwMUwnx6KJk=";
    };
    status_code = 200;
    headers = { "content-type" = "application/x-git-upload-pack-result"; };
  }
  {
    url = "https://github.com/fmtlib/fmt/git-upload-pack";
    file = fetchurl {
      url = "https://github.com/fmtlib/fmt/git-upload-pack";
      hash = "sha256-T9WPCziczWYuYs7xVKko2EnmEbqCF70TfDSbYZJNXOw=";
    };
    status_code = 200;
    headers = { "content-type" = "application/x-git-upload-pack-result"; };
  }
  {
    url =
      "https://github.com/ArthurSonzogni/ftxui/info/refs?service=git-upload-pack";
    file = fetchurl {
      url =
        "https://github.com/ArthurSonzogni/ftxui/info/refs?service=git-upload-pack";
      hash = "sha256-T7cqu0OhaMSQmgs6aeTfWeIazNF4S9v016xVpuGCr68=";
    };
    status_code = 200;
    headers = {
      "content-type" = "application/x-git-upload-pack-advertisement";
    };
  }
  {
    url = "https://github.com/ArthurSonzogni/ftxui/git-upload-pack";
    file = fetchurl {
      url = "https://github.com/ArthurSonzogni/ftxui/git-upload-pack";
      hash = "sha256-qa6xUG83JnlNpO4F+2GbC7ko5qaJEQGgzdMjdiTMTQc=";
    };
    status_code = 200;
    headers = { "content-type" = "application/x-git-upload-pack-result"; };
  }
  {
    url = "https://github.com/ArthurSonzogni/ftxui/git-upload-pack";
    file = fetchurl {
      url = "https://github.com/ArthurSonzogni/ftxui/git-upload-pack";
      hash = "sha256-FYi7e5tYfqt5fpJDKejSu7XjwFJnABy2qEsodfk4MZE=";
    };
    status_code = 200;
    headers = { "content-type" = "application/x-git-upload-pack-result"; };
  }
  {
    url =
      "https://github.com/p-ranav/argparse/info/refs?service=git-upload-pack";
    file = fetchurl {
      url =
        "https://github.com/p-ranav/argparse/info/refs?service=git-upload-pack";
      hash = "sha256-T7cqu0OhaMSQmgs6aeTfWeIazNF4S9v016xVpuGCr68=";
    };
    status_code = 200;
    headers = {
      "content-type" = "application/x-git-upload-pack-advertisement";
    };
  }
  {
    url = "https://github.com/p-ranav/argparse/git-upload-pack";
    file = fetchurl {
      url = "https://github.com/p-ranav/argparse/git-upload-pack";
      hash = "sha256-tdJCHsnzcKaeJXtOz16Kw1FcHgHajyLU8Bb/irKnAqc=";
    };
    status_code = 200;
    headers = { "content-type" = "application/x-git-upload-pack-result"; };
  }
  {
    url = "https://github.com/p-ranav/argparse/git-upload-pack";
    file = fetchurl {
      url = "https://github.com/p-ranav/argparse/git-upload-pack";
      hash = "sha256-wViIibdRgi8UmkHlBLc4ADeDbHSWDDEfTiLpVSQwCGA=";
    };
    status_code = 200;
    headers = { "content-type" = "application/x-git-upload-pack-result"; };
  }
  {
    url = "https://github.com/fmtlib/fmt/info/refs?service=git-upload-pack";
    file = fetchurl {
      url = "https://github.com/fmtlib/fmt/info/refs?service=git-upload-pack";
      hash = "sha256-T7cqu0OhaMSQmgs6aeTfWeIazNF4S9v016xVpuGCr68=";
    };
    status_code = 200;
    headers = {
      "content-type" = "application/x-git-upload-pack-advertisement";
    };
  }
  {
    url = "https://github.com/fmtlib/fmt/git-upload-pack";
    file = fetchurl {
      url = "https://github.com/fmtlib/fmt/git-upload-pack";
      hash = "sha256-VfWFMwZZ6RJhz4DMzNCLCPYtDYPKsMWyKwMUwnx6KJk=";
    };
    status_code = 200;
    headers = { "content-type" = "application/x-git-upload-pack-result"; };
  }
  {
    url = "https://github.com/fmtlib/fmt/git-upload-pack";
    file = fetchurl {
      url = "https://github.com/fmtlib/fmt/git-upload-pack";
      hash = "sha256-SMhPqNcYTDda0e3x49FVoE3eY54WZ84g42R+UxrQKmk=";
    };
    status_code = 200;
    headers = { "content-type" = "application/x-git-upload-pack-result"; };
  }
  {
    url =
      "https://github.com/ArthurSonzogni/ftxui/info/refs?service=git-upload-pack";
    file = fetchurl {
      url =
        "https://github.com/ArthurSonzogni/ftxui/info/refs?service=git-upload-pack";
      hash = "sha256-T7cqu0OhaMSQmgs6aeTfWeIazNF4S9v016xVpuGCr68=";
    };
    status_code = 200;
    headers = {
      "content-type" = "application/x-git-upload-pack-advertisement";
    };
  }
  {
    url = "https://github.com/ArthurSonzogni/ftxui/git-upload-pack";
    file = fetchurl {
      url = "https://github.com/ArthurSonzogni/ftxui/git-upload-pack";
      hash = "sha256-qa6xUG83JnlNpO4F+2GbC7ko5qaJEQGgzdMjdiTMTQc=";
    };
    status_code = 200;
    headers = { "content-type" = "application/x-git-upload-pack-result"; };
  }
  {
    url = "https://github.com/ArthurSonzogni/ftxui/git-upload-pack";
    file = fetchurl {
      url = "https://github.com/ArthurSonzogni/ftxui/git-upload-pack";
      hash = "sha256-xnsUqXp1rWcuKhDpBhRVW7gjE+Tsi4TXh9qjxgtvTK0=";
    };
    status_code = 200;
    headers = { "content-type" = "application/x-git-upload-pack-result"; };
  }
  {
    url =
      "https://github.com/p-ranav/argparse/info/refs?service=git-upload-pack";
    file = fetchurl {
      url =
        "https://github.com/p-ranav/argparse/info/refs?service=git-upload-pack";
      hash = "sha256-T7cqu0OhaMSQmgs6aeTfWeIazNF4S9v016xVpuGCr68=";
    };
    status_code = 200;
    headers = {
      "content-type" = "application/x-git-upload-pack-advertisement";
    };
  }
  {
    url = "https://github.com/p-ranav/argparse/git-upload-pack";
    file = fetchurl {
      url = "https://github.com/p-ranav/argparse/git-upload-pack";
      hash = "sha256-tdJCHsnzcKaeJXtOz16Kw1FcHgHajyLU8Bb/irKnAqc=";
    };
    status_code = 200;
    headers = { "content-type" = "application/x-git-upload-pack-result"; };
  }
  {
    url = "https://github.com/p-ranav/argparse/git-upload-pack";
    file = fetchurl {
      url = "https://github.com/p-ranav/argparse/git-upload-pack";
      hash = "sha256-Y64KmFqdnhXDLfLoZNyKLMOwGl9MN9Zlr1qud9/wuhY=";
    };
    status_code = 200;
    headers = { "content-type" = "application/x-git-upload-pack-result"; };
  }
]
