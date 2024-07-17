#include <webc/webc-templates/pss.h>
#include <webc/webc-actions.h>

int main(int argc, char** argv)
{
    WebcAction action = WEBC_ParseCliArgs(argc, argv);

    char* version = clib_format_text("v%s", VERSION);

    ProjectShowcaseSite site = {
        .author = "Konstantinos Despoinidis",
        .year = 2024,
        .email = "despoinidisk@gmail.com",
        .title = "WebC",
        .github_username = "KDesp73",
        .project.name = "webc",
        .project.desc= "Write and deploy websites using the C Programming Language.",
        .project.lang = "C",
        .project.link = "https://github.com/KDesp73/webc",
        .project.license = "MIT",
        .project.version = version,
        .project.image = "./webc-image.png"
    };

    Tree tree = WEBC_MakeTree("docs", 
        WEBC_MakeRoute("/", WEBC_TemplateProjectShowcaseSite(site)),
        NULL
    );
    
    WEBC_HandleAction(action, tree);
    free(version);
    
    return 0;
}
