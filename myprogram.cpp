#include <iostream>
#include <filesystem>

int main() {
    std::filesystem::path path("D:\\dir1");
    []([[maybe_unused]] const std::filesystem::path& path, const std::string& extension) {
        for(const auto& p: std::filesystem::recursive_directory_iterator("D:\\dir1")) {
            //if (std::filesystem::is_regular_file(p) && p.path().extension().compare(".jpg"))
            if (std::filesystem::is_regular_file(p) && p.path().extension() == extension)
                std::cout << p.path().filename() << std::endl;
        }
    }(path,(".txt"));
}
