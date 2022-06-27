#ifndef IMAGE_PROCESSOR__SKELETON_IMQUEUE_HPP
#define IMAGE_PROCESSOR__SKELETON_IMQUEUE_HPP

#include <filesystem>
#include <iostream>
#include <string>
#include <map>
#include <functional>
#include <utility>
#include "improc.hpp"

class TaskData {
public:
    std::filesystem::path input_filepath;
    std::function<Image(const Image&)> processing_function;
    std::filesystem::path output_dir;

    TaskData() = default;

    TaskData(const std::filesystem::path &inputFilepath, std::function<Image(const Image &)> func, const std::filesystem::path &outputDir) : input_filepath(
            inputFilepath), processing_function(std::move(func)), output_dir(outputDir) {}
};

using queue_type = std::map<std::string, TaskData>;

class TaskQueue {
private:
    queue_type queue;
public:
    TaskQueue() = default;
    ~TaskQueue() = default;
    void add_task(std::string task_id, TaskData task);
    void execute_all();
    const queue_type& get_all_tasks();
};

#endif //IMAGE_PROCESSOR__SKELETON_IMQUEUE_HPP
