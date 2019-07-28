from setuptools import setup, Extension


setup(
    name='monkeypatch',
    ext_modules=[
        Extension('monkeypatch', sources=[
            'src/monkeypatch.c',
        ]),
    ],
)
