<br/>
<p align="center">
  <h3 align="center">Spellcheck Lib</h3>

  <p align="center">
    A fast C++ spell checking & suggestion library
    <br/>
    <br/>
  </p>
</p>



## Table Of Contents

* [About the Project](#about-the-project)
* [Built With](#built-with)
* [Getting Started](#getting-started)
  * [Prerequisites](#prerequisites)
  * [Installation](#installation)
* [Roadmap](#roadmap)
* [Contributing](#contributing)
* [License](#license)
* [Authors](#authors)

## About The Project

A lightweight (close to 8mb when compiled with default dictionary) spell checking library, includes American, British, Canadian and Australian english words.

## Built With

C++ 17 & CMake 3.27

## Getting Started

The repository has a default `wordlist.txt` & `wordlist.h` which contain ~514,000 words. You may specify your own wordlists by either replacing the ones in `wordlist.txt` and then using 
```sh
xxd -i .\wordlist.txt > wordlist.h
```

### Prerequisites

* C++ 17 or higher
* CMake 3.27 or higher

### Installation



1. Clone the repo

```sh
git clone https://github.com/kotlinsyntax/SpellCheckLib.git
```

2. Build the library

```sh
cmake --build -j 8
```


## Roadmap

* Multi-language support

## Contributing

Contributions are what make the open source community such an amazing place to be learn, inspire, and create. Any contributions you make are **greatly appreciated**.
* If you have suggestions for adding or removing projects, feel free to [open an issue](https://github.com/kotlinsyntax/SpellCheckLib/issues/new) to discuss it, or directly create a pull request after you edit the *README.md* file with necessary changes.
* Please make sure you check your spelling and grammar.
* Create individual PR for each suggestion.
* Please also read through the [Code Of Conduct](https://github.com/kotlinsyntax/SpellCheckLib/blob/main/CODE_OF_CONDUCT.md) before posting your first idea as well.

### Creating A Pull Request

1. Fork the Project
2. Create your Feature Branch (`git checkout -b feature/AmazingFeature`)
3. Commit your Changes (`git commit -m 'Add some AmazingFeature'`)
4. Push to the Branch (`git push origin feature/AmazingFeature`)
5. Open a Pull Request

## License

Distributed under the MIT License. See [LICENSE](https://github.com/kotlinsyntax/SpellCheckLib/blob/main/LICENSE.md) for more information.

## Authors

* **KotlinSyntax** - [Github](https://github.com/kotlinsyntax/) - *Main Developer*

