//
// Created by cxc on 2024/1/4.
//

#include "plugin_loader.hpp"

#ifdef _WIN32
#define DLL_EXTENSION (".dll")
#define DLL_STD_CALL __stdcall
#else
#define DLL_EXTENSION (".so")
#define DLL_STD_CALL
#endif //_WIN32

namespace ss
{
namespace plugin
{
    std::shared_ptr<boost::dll::shared_library> loadPlugin(const std::string& file, ss::PluginFunctions& functions)
    {
        namespace fs = boost::filesystem;

        //文件校验
        fs::path path(file);
        if (!fs::exists(path) || !fs::is_regular_file(path) || path.extension() != DLL_EXTENSION)
        {
            return nullptr;
        }

        std::shared_ptr<boost::dll::shared_library> lib = std::make_shared<boost::dll::shared_library>(file);

        //必选接口
        constexpr const char* GetPluginGUID{ "GetPluginGUID" };
        constexpr const char* GetPluginName{ "GetPluginName" };
        constexpr const char* CreatePlugin{ "CreatePlugin" };

        //可选接口
        constexpr const char* GetPluginCategory{ "GetPluginCategory" };
        constexpr const char* GetPluginDescription{ "GetPluginDescription" };
        constexpr const char* GetPluginVersion{ "GetPluginVersion" };
        constexpr const char* GetPluginAuthor{ "GetPluginAuthor" };
        constexpr const char* GetPluginCategoryAdv{ "GetPluginCategoryAdv" };
        constexpr const char* GetPluginType{ "GetPluginType" };
        constexpr const char* InitPluginPlatform{ "InitPluginPlatform" };
        constexpr const char* UninitPluginPlatform{ "UninitPluginPlatform" };
        constexpr const char* DisposePlugin{ "DisposePlugin" };

        //加载资源
        if (lib->has(GetPluginGUID) && lib->has(GetPluginName) && lib->has(CreatePlugin))
        {
            functions.getPluginGUID = lib->get<const char * DLL_STD_CALL()>(GetPluginGUID);
            functions.getPluginName = lib->get<const char * DLL_STD_CALL()>(GetPluginName);
            functions.createPlugin = lib->get<void * DLL_STD_CALL(void*)>(CreatePlugin);

            //加载可选接口
            if (lib->has(GetPluginCategory))
            {
                functions.getPluginCategory = lib->get<int DLL_STD_CALL()>(GetPluginCategory);
            }
            else
            {
                functions.getPluginCategory = nullptr;
            }

            if (lib->has(GetPluginDescription))
            {
                functions.getPluginDescription = lib->get<const char * DLL_STD_CALL()>(GetPluginDescription);
            }
            else
            {
                functions.getPluginDescription = nullptr;
            }

            if (lib->has(GetPluginVersion))
            {
                functions.getPluginVersion = lib->get<const char * DLL_STD_CALL()>(GetPluginVersion);
            }
            else
            {
                functions.getPluginVersion = nullptr;
            }

            if (lib->has(GetPluginAuthor))
            {
                functions.getPluginAuthor = lib->get<const char * DLL_STD_CALL()>(GetPluginAuthor);
            }
            else
            {
                functions.getPluginAuthor = nullptr;
            }

            if (lib->has(GetPluginCategoryAdv))
            {
                functions.getPluginCategoryAdv = lib->get<const char * DLL_STD_CALL()>(GetPluginCategoryAdv);
            }
            else
            {
                functions.getPluginCategoryAdv = nullptr;
            }

            if (lib->has(GetPluginType))
            {
                functions.getPluginType = lib->get<int DLL_STD_CALL()>(GetPluginType);
            }
            else
            {
                functions.getPluginType = nullptr;
            }

            if (lib->has(InitPluginPlatform))
            {
                functions.initPluginPlatform = lib->get<void DLL_STD_CALL(const char*, int, int)>(InitPluginPlatform);
            }
            else
            {
                functions.initPluginPlatform = nullptr;
            }

            if (lib->has(UninitPluginPlatform))
            {
                functions.uninitPluginPlatform = lib->get<void DLL_STD_CALL()>(UninitPluginPlatform);
            }
            else
            {
                functions.uninitPluginPlatform = nullptr;
            }

            if (lib->has(DisposePlugin))
            {
                functions.disposePlugin = lib->get<void DLL_STD_CALL(void*)>(DisposePlugin);
            }
            else
            {
                functions.disposePlugin = nullptr;
            }

            return lib;
        }
        else
        {
            lib->unload();
        }

        return nullptr;
    }

    std::shared_ptr<boost::dll::shared_library> loadPlugin(const std::string& file, ss::UIPluginFunctions& functions)
    {
        namespace fs = boost::filesystem;

        //文件校验
        fs::path path(file);
        if (!fs::exists(path) || !fs::is_regular_file(path) || path.extension() != DLL_EXTENSION)
        {
            return nullptr;
        }

        std::shared_ptr<boost::dll::shared_library> lib = std::make_shared<boost::dll::shared_library>(file);

        //必选接口
        constexpr const char* GetPluginGUID{ "GetPluginGUID" };
        constexpr const char* CreatePluginUI{ "CreatePluginUI" };

        //可选接口
        constexpr const char* GetUIPlatform{ "GetUIPlatform" };
        constexpr const char* InitPluginPlatform{ "InitPluginPlatform" };
        constexpr const char* UninitPluginPlatform{ "UninitPluginPlatform" };
        constexpr const char* DisposePluginUI{ "DisposePluginUI" };

        //加载资源
        if (lib->has(GetPluginGUID) && lib->has(CreatePluginUI))
        {
            functions.getPluginGUID = lib->get<const char * DLL_STD_CALL()>(GetPluginGUID);
            functions.createPluginUI = lib->get<void * DLL_STD_CALL(void*, void*, void*)>(CreatePluginUI);

            //加载可选接口
            if (lib->has(GetUIPlatform))
            {
                functions.getUIPlatform = lib->get<int DLL_STD_CALL()>(GetUIPlatform);
            }
            else
            {
                functions.getUIPlatform = nullptr;
            }

            if (lib->has(InitPluginPlatform))
            {
                functions.initPluginPlatform = lib->get<void DLL_STD_CALL(const char*, int, int)>(InitPluginPlatform);
            }
            else
            {
                functions.initPluginPlatform = nullptr;
            }

            if (lib->has(UninitPluginPlatform))
            {
                functions.uninitPluginPlatform = lib->get<void DLL_STD_CALL()>(UninitPluginPlatform);
            }
            else
            {
                functions.uninitPluginPlatform = nullptr;
            }

            if (lib->has(DisposePluginUI))
            {
                functions.disposePluginUI = lib->get<void DLL_STD_CALL(void*)>(DisposePluginUI);
            }
            else
            {
                functions.disposePluginUI = nullptr;
            }

            return lib;
        }
        else
        {
            lib->unload();
        }

        return nullptr;
    }

} //namespace plugin
} //namespace ss