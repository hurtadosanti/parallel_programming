import pytest


def pytest_addoption(parser):
    parser.addoption(
        "--size", action="store", default="10", help="size of the test"
    )


@pytest.fixture
def size(request) -> int:
    return int(request.config.getoption("--size"))
